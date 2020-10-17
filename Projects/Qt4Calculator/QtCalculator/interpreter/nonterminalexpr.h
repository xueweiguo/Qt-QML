#ifndef NONTERMINALEXPR_H
#define NONTERMINALEXPR_H

#include"expr.h"
#include<QString>

class NonterminalExpr : public Expr
{
public:
    NonterminalExpr();
    virtual ~NonterminalExpr();

    void appendExpr(Expr* expr);
    void appendOperator(Token* token);

    class ValueOperator
    {
    public:
        ValueOperator():evaluateResult(0){}
        virtual ~ValueOperator(){};
        virtual bool evaluate(complex value1, complex value2) = 0;
        complex getResult(){return evaluateResult;}
        QString getErrorMessage(){return errorMessage;}
    protected:
        complex evaluateResult;
        QString errorMessage;
    };

    virtual bool evaluate(EvalulateContext& context);
    virtual ValueOperator* getValueOperator(QString /*operatorContent*/){ return NULL; }
protected:
    QList<Expr*> exprList;
    QList<Token*> operatorList;

};

template<typename ParentExpr, typename ChildExpr>
Expr* buildExprT(Expr::BuildContext& context, QString operatorRegex)
{
    Expr* firstExpr = ChildExpr::buildExpr(context);

    if(firstExpr == NULL) return NULL;

    if(context.tokenList.count() == 0) return firstExpr;

    Token* token = context.tokenList.first();

    if((token->getType() != Token::Operator)
       && (token->getType() != Token::Parenthese)
       && (token->getType() != Token::Comma))
    {
        context.errorMessage = "Invalid token";
        delete firstExpr;
        return NULL;
    }

    QString content = token->getContent();
    QRegExp regexp(operatorRegex);
    if(content.indexOf(regexp) != 0) return firstExpr;

    ParentExpr* parentExpr = new ParentExpr();
    parentExpr->appendExpr(firstExpr);
    parentExpr->appendOperator(token);
    context.tokenList.removeFirst();

    while(true)
    {
        Expr* expr = ChildExpr::buildExpr(context);

        if(expr == NULL) break;

        parentExpr->appendExpr(expr);

        if(context.tokenList.count() == 0) return parentExpr;

        token = context.tokenList.first();

        if((token->getType() != Token::Operator)
             && (token->getType() != Token::Parenthese))
        {
            context.errorMessage = "Invalid token:" + token->getContent();
            break;
        }

        QString content = token->getContent();
        QRegExp regexp(operatorRegex);
        if(content.indexOf(regexp) != 0) return parentExpr;

        parentExpr->appendOperator(token);
        context.tokenList.removeFirst();

        if(context.tokenList.count() == 0)
        {
            context.errorMessage = "Expression is't complete";
            break;
        }
    }
    delete parentExpr;
    return NULL;
}

#endif // NONTERMINALEXPR_H
