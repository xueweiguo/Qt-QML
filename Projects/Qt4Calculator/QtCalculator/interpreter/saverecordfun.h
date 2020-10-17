#ifndef SAVERECORDFUN_H
#define SAVERECORDFUN_H

#include"recordfun.h"

class SaveRecordFun : public RecordFun
{
public:
    SaveRecordFun(CalculateEngine* _engine);

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // SAVERECORDFUN_H
