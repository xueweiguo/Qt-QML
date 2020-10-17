#ifndef CALCULATEENGINE_H
#define CALCULATEENGINE_H

#include<QString>
#include<QMap>
#include<QList>

#include "calculatefunction.h"
#include "token.h"

class CalculateEngine
{
public:
    CalculateEngine();
    CalculateEngine(CalculateEngine& /*engine*/){}
    ~CalculateEngine();

    QList<Token*> analyzeToken(QString strQuestion);
    QString calculate(QString strQuestion);

    struct Record
    {
        Record():success(false),result(0){}
        bool success;
        QString question;
        complex result;
    };

    int getRecordCount();
    Record* getRecord(int index);
    bool clearRecord(int index);
    bool clearAllRecord();
    bool saveRecord();
    bool registerRecordFunction();
private:
    QString calculate(QList<Token*>& tokenList);
    Record* prevRecord;
    Record* currentRecord;
    QList<Record*> recordList;
};

#endif // CALCULATEENGINE_H
