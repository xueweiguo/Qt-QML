#ifndef TANRFUN_H
#define TANRFUN_H

#include"calculatefunction.h"

class TanrFun : public CalculateFunction
{
public:
    TanrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // TANRFUN_H
