#ifndef RECORDFUN_H
#define RECORDFUN_H

#include"calculatefunction.h"

class CalculateEngine;

class RecordFun : public CalculateFunction
{
public:
    RecordFun(CalculateEngine* _engine);
    ~RecordFun();
protected:
    CalculateEngine* engine;
    QString getRecordString();
};

#endif // RECORDFUN_H
