#include "cosdfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister funRegister(new CosdFun());

CosdFun::CosdFun()
{
}

QString CosdFun::getName()
{
    return "cosd";
}

QString CosdFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "cosd(x)\r\n";
    strInstruction += "Cosine function. Argument in degrees.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool CosdFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result = cos(para.r * M_PI / 180);
    if(fabs(result.r) < MIN_NUMBER)
    {
        result = 0;
    }
    return true;
}
