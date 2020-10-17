#include "clearrecordfun.h"
#include "functionmanager.h"

#include "calculateengine.h"

ClearRecordFun::ClearRecordFun(CalculateEngine* _engine)
    :RecordFun(_engine)
{
}

QString ClearRecordFun::getName()
{
    return "mc";
}

QString ClearRecordFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "mc(x)\r\n";
    strInstruction += "Clear calculate result.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    QString recordCount;
    recordCount.setNum(engine->getRecordCount());
    strInstruction += "x record index. must be >= 0 and < " + recordCount + ".\r\n";
    strInstruction += "----------Usable record.---------------\r\n";
    strInstruction += getRecordString();
    return strInstruction;
}

bool ClearRecordFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() == 0)
    {
        engine->clearAllRecord();
    }
    else
    {
        QList<int> indexList;
        foreach(complex comp, paraList)
        {
            indexList.append((int)comp.r);
        }
        qSort(indexList.begin(), indexList.end(), qGreater<int>());

        while(indexList.count() > 0)
        {
            if(!engine->clearRecord(indexList.takeFirst()))
            {
                message = getName() + ":Invalid input";
                return false;
            }
        }
    }
    result = 0;
    return true;
}
