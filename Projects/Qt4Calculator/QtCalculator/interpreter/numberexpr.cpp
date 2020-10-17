#include "numberexpr.h"

NumberExpr::NumberExpr()
{
}

NumberExpr::~NumberExpr()
{
}

void NumberExpr::setValueString(QString value)
{
    valueString = value;
}

bool NumberExpr::evaluate(EvalulateContext& context)
{
    context.resultStack.removeLast();
    complex value(valueString);
    context.resultStack.append(value);
    return true;
}
