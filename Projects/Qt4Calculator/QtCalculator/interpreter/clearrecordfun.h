#ifndef CLEARRECORDFUN_H
#define CLEARRECORDFUN_H

#include"recordfun.h"

class ClearRecordFun : public RecordFun
{
public:
    ClearRecordFun(CalculateEngine* _engine);

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // CLEARRECORDFUN_H
