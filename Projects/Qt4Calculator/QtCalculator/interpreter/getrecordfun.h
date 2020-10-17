#ifndef GETRECORDFUN_H
#define ACOSDFUN_H

#include"recordfun.h"

class GetRecordFun : public RecordFun
{
public:
    GetRecordFun(CalculateEngine* _engine);

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // GETRECORDFUN_H
