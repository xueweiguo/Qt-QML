#ifndef AVERAGEFUN_H
#define AVERAGEFUN_H

#include"calculatefunction.h"

class AverageFun : public CalculateFunction
{
public:
    AverageFun();

    virtual QString getName();
    virtual QString getInstruction();
    virtual bool execute(QList<complex> paraList, complex& result, QString& message);
};

#endif // AVERAGEFUN_H
