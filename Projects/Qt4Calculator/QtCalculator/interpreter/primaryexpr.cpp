#include "primaryexpr.h"
#include "numberexpr.h"
#include "additiveexpr.h"
#include "functionexpr.h"

PrimaryExpr::PrimaryExpr()
{
}

Expr* PrimaryExpr::buildExpr(BuildContext& context)
{
    if(context.tokenList.count() == 0) return NULL;

    Token* token = context.tokenList.first();
    switch(token->getType())
    {
    case Token::Number:
        {
            NumberExpr* expr = new NumberExpr();
            expr->setValueString(token->getContent());
            context.tokenList.removeFirst();
            delete token;
            return expr;
        }
    case Token::Parenthese:
        if(token->getContent() == "(")
        {
            context.tokenList.removeFirst();
            delete token;

            Expr* expr = AdditiveExpr::buildExpr(context);
            if(expr == NULL) return NULL;

            token = context.tokenList.takeFirst();
            if(token->getType() == Token::Parenthese && token->getContent() == ")")
            {
                delete token;
                return expr;
            }
            else
            {
                context.errorMessage = "\')\'is necessary";
                delete token;
                delete expr;
                return NULL;
            }

        }
        else
        {
            context.errorMessage = "\'(\'is necessary";
            return NULL;
        }
    case Token::FunctionName:
        return FunctionExpr::buildExpr(context);
    default:
        return NULL;
    }
    return NULL;
}
