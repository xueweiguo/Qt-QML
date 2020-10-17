#ifndef SINDFUN_H
#define SINDFUN_H

#include"calculatefunction.h"

class SindFun : public CalculateFunction
{
public:
    SindFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // SINDFUN_H
