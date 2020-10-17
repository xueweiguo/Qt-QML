#ifndef ACOSRFUN_H
#define ACOSRFUN_H

#include"calculatefunction.h"

class AcosrFun : public CalculateFunction
{
public:
    AcosrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ACOSRFUN_H
