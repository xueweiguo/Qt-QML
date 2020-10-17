#include "logfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new LogFun());

LogFun::LogFun()
{
}

QString LogFun::getName()
{
    return "ln";
}

QString LogFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "ln(x) -\r\n";
    strInstruction += "Natural logarithm.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real and its value must be greater than zero.\r\n";
    return strInstruction;
}

bool LogFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 1)
    {
        message = getName() + ":Invalid parameter count";
        return false;
    }
    complex para = paraList.first();
    if(para.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    if(para.r <= 0)
    {
        message = getName() + ":Invalid input";
        return false;
    }

    result = log(para.r);
    return true;
}
