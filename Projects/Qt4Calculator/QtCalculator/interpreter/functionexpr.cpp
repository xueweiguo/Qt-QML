#include "functionexpr.h"
#include "additiveexpr.h"
#include "functionmanager.h"

FunctionExpr::FunctionExpr(QString name)
    :functionName(name)
{
}

FunctionExpr::~FunctionExpr()
{
}

Expr* FunctionExpr::buildExpr(BuildContext& context)
{
    Token* token = NULL;
    QString functionName;

    token = context.tokenList.first();
    if(token->getType() != Token::FunctionName) return NULL;
    functionName = token->getContent();
    delete context.tokenList.takeFirst();

    if(context.tokenList.count() == 0)
    {
        context.errorMessage = "Expression is't complete";
        return NULL;
    }

    token = context.tokenList.first();
    if(token->getType() != Token::Parenthese || token->getContent() != "(")
    {
        context.errorMessage = "\'(\'is necessary";
        return NULL;
    }
    delete context.tokenList.takeFirst();

    if(context.tokenList.count() == 0)
    {
        context.errorMessage = "Expression is't complete";
        return NULL;
    }

    FunctionExpr* funExpr = new FunctionExpr(functionName);

    token = context.tokenList.first();
    if(token->getType() == Token::Parenthese && token->getContent() == ")")
    {
        delete context.tokenList.takeFirst();
        return funExpr;
    }

    while(true)
    {
        Expr* expr = AdditiveExpr::buildExpr(context);
        if(expr == NULL) break;
        funExpr->appendExpr(expr);

        if(context.tokenList.count() == 0)
        {
            context.errorMessage = "Expression is't complete";
            break;
        }

        token = context.tokenList.first();
        if(token->getType() == Token::Comma)
        {
            delete context.tokenList.takeFirst();
        }
        else if(token->getType() == Token::Parenthese && token->getContent() == ")")
        {
            delete context.tokenList.takeFirst();
            return funExpr;
        }
        else
        {
            context.errorMessage = functionName + " parameter error";
            break;
        }
    }

    delete funExpr;
    return NULL;
}

bool FunctionExpr::evaluate(EvalulateContext& context)
{
    complex zero(0);
    context.resultStack.append(zero);
    QList<complex> paraList;
    foreach(Expr* expr, exprList)
    {
        if(expr->evaluate(context))
        {
            paraList.append(context.resultStack.last());
        }
        else
        {
            return false;
        }
    }
    context.resultStack.removeLast();

    FunctionManager* manager = FunctionManager::getInstance();
    CalculateFunction* fun = manager->getFunction(functionName);
    if(fun == NULL)
    {
        context.errorMessage = "Can't found the function:" + functionName;
        return false;
    }
    complex result;
    if(fun->execute(paraList, result, context.errorMessage))
    {
        context.resultStack.removeLast();
        context.resultStack.append(result);
        return true;
    }
    else
    {
        return false;
    }
}
