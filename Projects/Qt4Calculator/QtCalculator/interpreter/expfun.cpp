#include "expfun.h"
#include "functionmanager.h"

static FunctionManager::FunctionRegister  funRegister(new ExpFun());

ExpFun::ExpFun()
{
}

QString ExpFun::getName()
{
    return "exp";
}

QString ExpFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "exp(x)r\n";
    strInstruction += "Exponential.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool ExpFun::execute(QList<complex> /*paraList*/, complex& /*result*/, QString& /*message*/)
{
    return false;
}
