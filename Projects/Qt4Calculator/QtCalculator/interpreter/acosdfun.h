#ifndef ACOSDFUN_H
#define ACOSDFUN_H

#include"calculatefunction.h"

class AcosdFun : public CalculateFunction
{
public:
    AcosdFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ACOSDFUN_H
