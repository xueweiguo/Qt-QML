#include "rootfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new RootFun());

RootFun::RootFun()
{
}

QString RootFun::getName()
{
    return "root";
}

QString RootFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "root(x, y)\r\n";
    strInstruction += "get the y times root of value x.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real and y must not be 0\r\n";
    return strInstruction;
}

bool RootFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    if(y.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    if(y.r == 0)
    {
        message = getName() + ":Invalid input";
        return false;
    }
    result = pow(x.r, 1/y.r);
    return checkError(message);
}
