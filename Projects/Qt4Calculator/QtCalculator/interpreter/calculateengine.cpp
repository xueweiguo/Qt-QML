#include "calculateengine.h"

#include <QtAlgorithms>
#include <QRegExp>

#include "functionmanager.h"
#include "token.h"
#include "tokenanalyzer.h"

#include "additiveexpr.h"

#include "saverecordfun.h"
#include "clearrecordfun.h"
#include "getrecordfun.h"

CalculateEngine::CalculateEngine()
    :prevRecord(NULL), currentRecord(NULL)
{
}

CalculateEngine::~CalculateEngine()
{
    if(prevRecord != NULL)
    {
        delete prevRecord;
    }
    if(currentRecord != NULL)
    {
        delete currentRecord;
    }
}

QList<Token*> CalculateEngine::analyzeToken(QString strQuestion)
{
    typedef TokenAnalyzer<Token, Token::EType, QList<Token*>::iterator> MyAnalyzer;

    class MyFactory : public MyAnalyzer::TokenPatternFactory
    {
        virtual int createPatterns(QList<MyAnalyzer::TokenPattern*>& list) const
        {
            FunctionManager* manager = FunctionManager::getInstance();
            QList<QString> functions = manager->functions();

            QString funPattern;
            foreach(QString funName, functions)
            {
                if(funPattern.length() > 0)
                {
                    funPattern += "|";
                }
                funPattern += funName;
            }
            list.append(new MyAnalyzer::TokenPattern(Token::FunctionName, funPattern));

            list.append(new MyAnalyzer::TokenPattern(Token::Number, "(((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))[eE][+-]?[0-9]+)?i"));
            list.append(new MyAnalyzer::TokenPattern(Token::Number, "((\\.[0-9]+)|([0-9]+\\.[0-9]*))?i"));
            list.append(new MyAnalyzer::TokenPattern(Token::Number, "([0-9]+)?i"));
            list.append(new MyAnalyzer::TokenPattern(Token::Number, "((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))[eE][+-]?[0-9]+"));
            list.append(new MyAnalyzer::TokenPattern(Token::Number, "(\\.[0-9]+)|([0-9]+\\.[0-9]*)"));
            list.append(new MyAnalyzer::TokenPattern(Token::Number, "[0-9]+"));
            list.append(new MyAnalyzer::TokenPattern(Token::Operator, "[-+*/%]"));
            list.append(new MyAnalyzer::TokenPattern(Token::Parenthese, "[()]"));
            list.append(new MyAnalyzer::TokenPattern(Token::Comma, ","));

            return list.count();
        }
    };

    MyFactory factory;

    MyAnalyzer analyzer;
    QList<Token*> tokenList = analyzer.analyzeToken(strQuestion, &factory);
    return tokenList;
}

QString CalculateEngine::calculate(QString strQuestion)
{
    if(prevRecord != NULL) delete prevRecord;
    prevRecord = currentRecord;
    currentRecord = new Record;
    QList<Token*> tokenList = analyzeToken(strQuestion);
    currentRecord->question = strQuestion;
    QString result = calculate(tokenList);
    qDeleteAll(tokenList);
    return result;
}

QString CalculateEngine::calculate(QList<Token*>& tokenList)
{
    QString result;

    QString unknownToken;
    foreach(Token* token, tokenList)
    {
        if(token->getType() == Token::NoType)
        {
            if(unknownToken.length() > 0)
            {
                unknownToken += ",";
            }
            unknownToken += token->getContent();
        }
    }
    if(unknownToken.length() > 0)
    {
        currentRecord->success = false;
        return "Unknown keyword:" + unknownToken;
    }

    Expr::BuildContext bContext(tokenList);

    Expr* expr = AdditiveExpr::buildExpr(bContext);
    if(expr != NULL)
    {
        Expr::EvalulateContext eContext;
        if(expr->evaluate(eContext))
        {
            currentRecord->success = true;
            currentRecord->result = eContext.resultStack.last();
            result = eContext.resultStack.last().toString();
        }
        else
        {
            currentRecord->success = false;
            result = eContext.errorMessage;
        }
        delete expr;
    }
    else
    {
        currentRecord->success = false;
        result = bContext.errorMessage;
    }
    return result;
}

int CalculateEngine::getRecordCount()
{
    return recordList.count();
}

CalculateEngine::Record* CalculateEngine::getRecord(int index)
{
    if(index >= 0 && index < recordList.count())
    {
        return recordList.at(index);
    }
    else
    {
        return NULL;
    }
}

bool CalculateEngine::clearRecord(int index)
{
    if(index >= 0 && index < recordList.count())
    {
        recordList.removeAt(index);
        return true;
    }
    else
    {
        return false;
    }
}

bool CalculateEngine::clearAllRecord()
{
    recordList.clear();
    return true;
}

bool CalculateEngine::saveRecord()
{
    if(prevRecord != NULL && prevRecord->success)
    {
        recordList.append(prevRecord);
        prevRecord = NULL;
    }
    return true;
}

bool CalculateEngine::registerRecordFunction()
{
    FunctionManager* manager = FunctionManager::getInstance();
    manager->registerFunction(new SaveRecordFun(this));
    manager->registerFunction(new ClearRecordFun(this));
    manager->registerFunction(new GetRecordFun(this));
    return true;
}
