#include "log10fun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new Log10Fun());

Log10Fun::Log10Fun()
{
}

QString Log10Fun::getName()
{
    return "log10";
}

QString Log10Fun::getInstruction()
{
    QString strInstruction;
    strInstruction += "log10(x)\r\n";
    strInstruction += "Common logarithm.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "must be of type real. The value of X must be greater than zero.\r\n";
    return strInstruction;
}

bool Log10Fun::execute(QList<complex> paraList, complex& result, QString& message)
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

    result = log10(para.r);
    return true;
}
