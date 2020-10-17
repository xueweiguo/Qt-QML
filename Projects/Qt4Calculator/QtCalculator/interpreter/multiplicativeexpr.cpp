#include "multiplicativeexpr.h"
#include "unaryexpr.h"

MultiplicativeExpr::MultiplicativeExpr()
{
}

MultiplicativeExpr::~MultiplicativeExpr()
{
}

Expr* MultiplicativeExpr::buildExpr(BuildContext& context)
{
   return buildExprT<MultiplicativeExpr, UnaryExpr>(context, "[*/%]");
}

NonterminalExpr::ValueOperator* MultiplicativeExpr::getValueOperator(QString operatorContent)
{
    class MyOperator : public ValueOperator
    {
    public:
        MyOperator(QString _operatorString):operatorString(_operatorString){}
        virtual bool evaluate(complex value1, complex value2)
        {
            if(operatorString == "*")
            {
                evaluateResult = value1 * value2;
                return true;
            }
            else if(operatorString == "/" && value2.getAbs() > 0)
            {
                evaluateResult = value1 / value2;
                return true;
            }
            else if(value1.i == 0 && value2.i == 0 && operatorString == "%")
            {
                evaluateResult = (long)value1.r % (long)value2.r;
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

