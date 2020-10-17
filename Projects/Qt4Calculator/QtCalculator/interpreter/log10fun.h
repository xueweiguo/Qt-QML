#ifndef LOG10FUN_H
#define LOG10FUN_H

#include"calculatefunction.h"

class Log10Fun : public CalculateFunction
{
public:
    Log10Fun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // LOG10FUN_H
