#ifndef ATANDFUN_H
#define ATANDFUN_H

#include"calculatefunction.h"

class AtandFun : public CalculateFunction
{
public:
    AtandFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // ATANDFUN_H
