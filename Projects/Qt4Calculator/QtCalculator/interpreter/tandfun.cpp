#include "tandfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister funRegister(new TandFun());

TandFun::TandFun()
{
}

QString TandFun::getName()
{
    return "tand";
}

QString TandFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "tand(x)\r\n";
    strInstruction += "Tangent function. Argument in degrees.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool TandFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    double dpara = para.r * M_PI / 180;
    if(fabs(fabs(dpara) - M_PI_2) < 0.0000000000001)
    {
        message = getName() + ":Invalid input";
        return false;
    }

    clearError();
    result = tan(dpara);
    return checkError(message);
}
