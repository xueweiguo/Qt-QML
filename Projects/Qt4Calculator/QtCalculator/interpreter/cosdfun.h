#ifndef COSDFUN_H
#define COSDFUN_H

#include"calculatefunction.h"

class CosdFun : public CalculateFunction
{
public:
    CosdFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // COSDFUN_H
