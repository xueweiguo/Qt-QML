#include "averagefun.h"
#include "functionmanager.h"

static FunctionManager::FunctionRegister funRegister(new AverageFun());

AverageFun::AverageFun()
{
}

QString AverageFun::getName()
{
    return "average";
}

QString AverageFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "average(x1,x2,x3,...xn)\r\n";
    strInstruction += "Calcualte the average value of intput values.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "x1,x2,x3,...xn must be of type real.\r\n";
    return strInstruction;
}

bool AverageFun::execute(QList<complex> paraList, complex& result, QString& message)
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
    result /= paraList.count();
    return true;
}
