#ifndef LOGFUN_H
#define LOGFUN_H

#include"calculatefunction.h"

class LogFun : public CalculateFunction
{
public:
    LogFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // LOGFUN_H
