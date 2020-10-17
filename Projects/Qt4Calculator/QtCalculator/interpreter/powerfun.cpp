#include "powerfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new PowerFun());

PowerFun::PowerFun()
{
}

QString PowerFun::getName()
{
    return "power";
}

QString PowerFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "power(x,y)\r\n";
    strInstruction += "Returns the value of x raised to the power of y. That is, x is the base and y is the exponent.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x, y any value.\r\n";
    return strInstruction;
}

bool PowerFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 2)
    {
        message = getName() + ":Invalid parameter count";
        return false;
    }
    clearError();
    complex x = paraList.takeFirst();
    if(x.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    complex y = paraList.takeFirst();
    if(x.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    result = pow(x.r, y.r);
    return checkError(message);
}
