#include "asindfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister asindRegister(new AsindFun());

AsindFun::AsindFun()
{
}

QString AsindFun::getName()
{
    return "asind";
}

QString AsindFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "asind(x) -\r\n";
    strInstruction += "Arcsine (inverse sine) function. Result in degrees.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "must be of type real. Its value must satisfy the inequality |X| <= 1. \r\n";
    return strInstruction;
}

bool AsindFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    if(para.r >= -1.0 && para.r <= 1.0)
    {
        result = asin(para.r) * 180 / M_PI;
        return true;
    }
    else
    {
        message = getName() + ":Invalid input";
        return false;
    }
}
