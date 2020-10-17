#include "getrecordfun.h"
#include "functionmanager.h"

#include "calculateengine.h"

GetRecordFun::GetRecordFun(CalculateEngine* _engine)
    :RecordFun(_engine)
{
}

QString GetRecordFun::getName()
{
    return "m";
}

QString GetRecordFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "m(x) -\r\n";
    strInstruction += "get the saved calculate result.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    QString recordCount;
    recordCount.setNum(engine->getRecordCount());
    strInstruction += "x record index. must be >= 0 and < " + recordCount + ".\r\n";
    strInstruction += "----------Usable record---------------\r\n";
    strInstruction += getRecordString();
    return strInstruction;
}

bool GetRecordFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() != 1)
    {
        message = getName() + ":Invalid input";
        return false;
    }
    else
    {
        int index = paraList.first().r;
        CalculateEngine::Record* record = engine->getRecord(index);
        if(record != NULL)
        {
            result = record->result;
            return true;
        }
        else
        {
            message = getName() + ":Invalid input";
            return false;
        }
    }
}
