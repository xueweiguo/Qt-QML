#include "atandfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister funRegister(new AtandFun());

AtandFun::AtandFun()
{
}

QString AtandFun::getName()
{
    return "atand";
}

QString AtandFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "atand(x) -\r\n";
    strInstruction += "Arctangent (inverse tangent) function. Result in degrees..\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool AtandFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result =atan(para.r) * 180 / M_PI;
    return true;
}
