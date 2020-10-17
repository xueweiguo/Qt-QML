#include "additiveexpr.h"
#include "multiplicativeexpr.h"

AdditiveExpr::AdditiveExpr()
{
}

AdditiveExpr::~AdditiveExpr()
{

}

NonterminalExpr::ValueOperator* AdditiveExpr::getValueOperator(QString operatorContent)
{
    class MyOperator : public ValueOperator
    {
    public:
        MyOperator(QString _operatorString):ValueOperator(),operatorString(_operatorString){}
        virtual bool evaluate(complex value1, complex value2)
        {
            if(operatorString == "+")
            {
                evaluateResult = value1 + value2;
                return true;
            }
            else if(operatorString == "-")
            {
                evaluateResult = value1 - value2;
                return true;
            }
            else
            {
                errorMessage = "Invalid parameter.";
                return false;
            }
        }

    private:
        QString operatorString;
    };
    return new MyOperator(operatorContent);
}

Expr* AdditiveExpr::buildExpr(BuildContext& context)
{
    return buildExprT<AdditiveExpr, MultiplicativeExpr>(context, "[-+]");
}
