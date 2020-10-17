#include "cosrfun.h"
#include "functionmanager.h"

#include <math.h>

static FunctionManager::FunctionRegister funRegister(new CosrFun());

CosrFun::CosrFun()
{
}

QString CosrFun::getName()
{
    return "cosr";
}

QString CosrFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "cosr(x)\r\n";
    strInstruction += "Cosine function.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type real.\r\n";
    return strInstruction;
}

bool CosrFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result = cos(para.r);
    if(fabs(result.r) < MIN_NUMBER)
    {
        result = 0;
    }
    return true;
}
