#include "saverecordfun.h"
#include "functionmanager.h"

#include "calculateengine.h"

SaveRecordFun::SaveRecordFun(CalculateEngine* _engine)
    :RecordFun(_engine)
{
}

QString SaveRecordFun::getName()
{
    return "ms";
}

QString SaveRecordFun::getInstruction()
{
    QString strInstruction;
    strInstruction += "ms() -\r\n";
    strInstruction += "Save result.\r\n";
    strInstruction += "Argument type and attributes\r\n";
    strInstruction += "none.\r\n";
    return strInstruction;
}

bool SaveRecordFun::execute(QList<complex> paraList, complex& result, QString& message)
{
    if(paraList.count() > 0)
    {
        message = getName() + ":Invalid input";
        return false;
    }
    engine->saveRecord();
    result = 0;
    return true;
}
