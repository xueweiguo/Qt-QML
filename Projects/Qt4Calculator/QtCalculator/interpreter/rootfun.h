#ifndef ROOTFUN_H
#define ROOTFUN_H

#include"calculatefunction.h"

class RootFun : public CalculateFunction
{
public:
    RootFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ROOTFUN_H
