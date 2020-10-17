#include "atanrfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new AtanrFun());

AtanrFun::AtanrFun()
{
}

QString AtanrFun::getName()
{
    return "atanr";
}

QString AtanrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "atanr(x)\r\n";
    strInstruction += "Arctangent (inverse tangent) function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool AtanrFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result =atan(para.r);
    return true;
}
