#ifndef EXPFUN_H
#define EXPFUN_H

#include"calculatefunction.h"

class ExpFun : public CalculateFunction
{
public:
    ExpFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ACOSDFUN_H
