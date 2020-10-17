#include "asinrfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new AsinrFun());

AsinrFun::AsinrFun()
{
}

QString AsinrFun::getName()
{
    return "asinr";
}

QString AsinrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "asinr(x) -\r\n";
    strInstruction += "Arcsine (inverse sine) function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "must be of type real. Its value must satisfy the inequality |X| <= 1. \r\n";
    return strInstruction;
}

bool AsinrFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 1)
    {
        message = getName() + ":Invalid parameter count";
        return false;
    }
    complex para = paraList.first();
    if(para.r >= -1.0 && para.r <= 1.0)
    {
        result =asin(para.r);
        return true;
    }
    else
    {
        message = getName() + ":Invalid input";
        return false;
    }
}
