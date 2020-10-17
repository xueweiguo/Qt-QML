#include "nonterminalexpr.h"

NonterminalExpr::NonterminalExpr()
{
}

NonterminalExpr::~NonterminalExpr()
{
    qDeleteAll(exprList);
    qDeleteAll(operatorList);
}

void NonterminalExpr::appendExpr(Expr* expr)
{
    exprList.append(expr);
}

void NonterminalExpr::appendOperator(Token* token)
{
    operatorList.append(token);
}

bool NonterminalExpr::evaluate(EvalulateContext& context)
{
    QList<Expr*>::iterator expr_it  = exprList.begin();

    context.resultStack.append(0);

    if(!(*expr_it)->evaluate(context)) return false;

    expr_it++;

    QList<Token*>::iterator operator_it = operatorList.begin();

    if(exprList.end() - expr_it == operatorList.end() - operator_it)
    {
        while(expr_it != exprList.end())
        {
            complex res_prev = context.resultStack.last();
            (*expr_it)->evaluate(context);
            complex res_cur = context.resultStack.takeLast();
            ValueOperator* valueOperator = this->getValueOperator((*operator_it)->getContent());
            if(valueOperator->evaluate(res_prev, res_cur))
            {
                context.resultStack.append(valueOperator->getResult());
                delete valueOperator;
            }
            else
            {
                context.resultStack.clear();
                context.errorMessage = valueOperator->getErrorMessage();
                delete valueOperator;
                return false;
            }
            operator_it++;
            expr_it++;
        }
        complex result_all = context.resultStack.takeLast();
        context.resultStack.removeLast();
        context.resultStack.append(result_all);
        return true;
    }
    else
    {
        context.resultStack.clear();
        context.errorMessage = "Operator count and Expr count is not match.";
        return false;
    }
}
