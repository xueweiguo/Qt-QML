#include "acosrfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister acosrRegister(new AcosrFun());

AcosrFun::AcosrFun()
{
}

QString AcosrFun::getName()
{
    return "acosr";
}

QString AcosrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "acosr(x) -\r\n";
    strInstruction += "Arccosine (inverse cosine) function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real. Its value must satisfy the inequality |X| <= 1.\r\n";
    return strInstruction;
}

bool AcosrFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    if(para.r >= -1.0 && para.r <= 1.0)
    {
        result = acos(para.r);
        return true;
    }
    else
    {
        message = getName() + ":Invalid input";
        return false;
    }
}
