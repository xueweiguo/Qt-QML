#include "sinrfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new SinrFun());

SinrFun::SinrFun()
{
}

QString SinrFun::getName()
{
    return "sinr";
}

QString SinrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "sinr(x)\r\n";
    strInstruction += "Sine function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real or complex. If X is real, it is regarded as a value in radians. If X is complex, its real and imaginary parts are regarded as values in radians.\r\n";
    return strInstruction;
}

bool SinrFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result =sin(para.r);
    if(fabs(result.r) < MIN_NUMBER)
    {
        result = 0;
    }
    return true;
}
