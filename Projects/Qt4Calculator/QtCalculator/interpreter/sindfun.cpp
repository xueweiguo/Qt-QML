#include "sindfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister funRegister(new SindFun());

SindFun::SindFun()
{
}

QString SindFun::getName()
{
    return "sind";
}

QString SindFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "sind(x)\r\n";
    strInstruction += "Sine function. Argument in degrees.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool SindFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 1)
    {
        message = getName() + ":Invalid parameter count.";
        return false;
    }
    complex para = paraList.first();
    if(para.i != 0)
    {
        message = getName() + "Invalid date type";
        return false;
    }
    result =sin(para.r * M_PI / 180);
    if(fabs(result.r) < MIN_NUMBER)
    {
        result = 0;
    }

    return true;
}
