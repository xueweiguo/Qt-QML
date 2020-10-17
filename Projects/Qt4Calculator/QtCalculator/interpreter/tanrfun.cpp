#include "tanrfun.h"
#include "functionmanager.h"

#define _USE_MATH_DEFINES
#include <math.h>

static FunctionManager::FunctionRegister tanrRegister(new TanrFun());

TanrFun::TanrFun()
{
}

QString TanrFun::getName()
{
    return "tanr";
}

QString TanrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "tanr(x)\r\n";
    strInstruction += "Tangent function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool TanrFun::execute(QList<complex> paraList, complex& result, QString& message)
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

    if(fabs(fabs(para.r) - M_PI_2) < 0.0000000000001)
    {
        message = getName() + ":Invalid input";
        return false;
    }

    clearError();
    result = tan(para.r);
    return checkError(message);
}
