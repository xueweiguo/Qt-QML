#ifndef POWERFUN_H
#define POWERFUN_H

#include"calculatefunction.h"

class PowerFun : public CalculateFunction
{
public:
    PowerFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // POWERFUN_H
