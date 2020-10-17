#include "factorialfun.h"
#include "functionmanager.h"

static FunctionManager::FunctionRegister funRegister(new FactorialFun());

FactorialFun::FactorialFun()
{
}

QString FactorialFun::getName()
{
    return "n!";
}

QString FactorialFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "n!(x) -\r\n";
    strInstruction += "Calculate factorial of input value.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x must be of type integer and >= 1\r\n";
    return strInstruction;
}

bool FactorialFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    int ipara = (int)para.r;
    if(ipara <= 0)
    {
        message = getName() + ":Invalid input";
        return false;
    }

    result = 1;
    for(int i = 1; i <= ipara; ++i)
    {
        result *= i;
    }
    return true;
}
