#ifndef COSRFUN_H
#define COSRFUN_H

#include"calculatefunction.h"

class CosrFun : public CalculateFunction
{
public:
    CosrFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // COSRFUN_H
