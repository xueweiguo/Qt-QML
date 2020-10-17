#ifndef ASINRFUN_H
#define ASINRFUN_H

#include"calculatefunction.h"

class AsinrFun : public CalculateFunction
{
public:
    AsinrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ASINRFUN_H
