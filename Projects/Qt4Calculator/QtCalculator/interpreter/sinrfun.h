#ifndef SINRFUN_H
#define SINRFUN_H

#include"calculatefunction.h"

class SinrFun : public CalculateFunction
{
public:
    SinrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // SINRFUN_H
