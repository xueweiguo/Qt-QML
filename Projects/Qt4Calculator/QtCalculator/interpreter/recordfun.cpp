#include "recordfun.h"

#include"calculateengine.h"

RecordFun::RecordFun(CalculateEngine* _engine)
    :engine(_engine)
{
}

RecordFun::~RecordFun()
{

}

QString RecordFun::getRecordString()
{
    QString recordString;
    for(int i = 0; i < engine->getRecordCount(); ++i)
    {
        CalculateEngine::Record* record = engine->getRecord(i);
        QString number;
        number.setNum(i);
        recordString += number;
        recordString += ":";
        recordString += record->result.toString();
        recordString += "(" + record->question + ")\r\n";
    }
    return recordString;
}
