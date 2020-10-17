#include "sumfun.h"
#include "functionmanager.h"

static FunctionManager::FunctionRegister funRegister(new SumFun());

SumFun::SumFun()
{
}

QString SumFun::getName()
{
    return "sum";
}

QString SumFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "sum(x1,x2,x3,x4,...xn) -\r\n";
    strInstruction += "Calcuate the sum of input parameters.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x1,x2,...xn any number. \r\n";
    return strInstruction;
}

bool SumFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() == 0)
    {
        message = getName() + ":Invalid parameter count";
        return false;
    }
    result =0;
    foreach(complex value, paraList)
    {
        result += value;
    }
    return true;
}
