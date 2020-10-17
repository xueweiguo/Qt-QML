#ifndef FACTORIALFUN_H
#define FACTORIALFUN_H

#include"calculatefunction.h"

class FactorialFun : public CalculateFunction
{
public:
    FactorialFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // FACTORIALFUN_H
