#include "unaryexpr.h"
#include "terminalexpr.h"
#include "primaryexpr.h"

UnaryExpr::UnaryExpr()
    :primaryExpr(NULL)
{
}

UnaryExpr::~UnaryExpr()
{
    if(primaryExpr != NULL)
    {
        delete primaryExpr;
        primaryExpr = NULL;
    }
}

Expr* UnaryExpr::buildExpr(BuildContext& context)
{
    int minusCount = 0;
    while(context.tokenList.count() > 0 &&
          context.tokenList.first()->getType() == Token::Operator)
    {
        QString content = context.tokenList.first()->getContent();
        if(content == "-")
        {
            ++minusCount;
        }
        else if(content != "+")
        {
            context.errorMessage = "Invalid token:" + content;
            return NULL;
        }
        delete context.tokenList.takeFirst();
    }

    if(context.tokenList.count() == 0)
    {
        context.errorMessage = "Expression is't complete";
        return NULL;
    }

    Expr* expr = PrimaryExpr::buildExpr(context);

    if(expr == NULL) return NULL;

    if((minusCount % 2) == 1)
    {
        UnaryExpr* unary = new UnaryExpr();
        unary->setPrimaryExpr(expr);
        return unary;
    }
    else
    {
        return expr;
    }
}

void UnaryExpr::setPrimaryExpr(Expr* expr)
{
    primaryExpr = expr;
}

bool UnaryExpr::evaluate(EvalulateContext& context)
{
    if(primaryExpr->evaluate(context))
    {
        complex result = context.resultStack.takeLast();
        result.r = -result.r;
        result.i = -result.i;
        context.resultStack.append(result);
        return true;
    }
    else
    {
        return false;
    }
}
