#ifndef ASINDFUN_H
#define ASINDFUN_H

#include"calculatefunction.h"

class AsindFun : public CalculateFunction
{
public:
    AsindFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};


#endif // ASINDFUN_H
