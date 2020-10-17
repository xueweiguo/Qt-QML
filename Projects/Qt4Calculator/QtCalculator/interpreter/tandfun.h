#ifndef TANDFUN_H
#define TANDFUN_H

#include"calculatefunction.h"

class TandFun : public CalculateFunction
{
public:
    TandFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // TANDFUN_H
