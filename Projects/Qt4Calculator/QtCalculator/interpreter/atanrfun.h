#ifndef ATANRFUN_H
#define ATANRFUN_H

#include"calculatefunction.h"

class AtanrFun : public CalculateFunction
{
public:
    AtanrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ATANRFUN_H
