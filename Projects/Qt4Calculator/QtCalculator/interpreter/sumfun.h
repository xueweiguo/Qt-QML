#ifndef SUMFUN_H
#define SUMFUN_H

#include"calculatefunction.h"

class SumFun : public CalculateFunction
{
public:
    SumFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // SUMFUN_H
