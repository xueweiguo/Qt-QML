#include "acosdfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister acosRegister(new AcosdFun());

AcosdFun::AcosdFun()
{
}

QString AcosdFun::getName()
{
    return "acosd";
}

QString AcosdFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "acosd(x) -\r\n";
    strInstruction += "Arccosine (inverse cosine) function. Result in degrees.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real. Its value must satisfy the inequality |X| <= 1.\r\n";
    return strInstruction;
}

bool AcosdFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 1)
    {
        message = getName() + "Invalid parameter count";
        return false;
    }
    complex para = paraList.first();
    if(para.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    clearError();
    result = acos(para.r) * 180 / M_PI;
    return checkError(message);
}
