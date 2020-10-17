#ifndef CALCULATEFUNCTION_H
#define CALCULATEFUNCTION_H

#include<QString>
#include<QList>

#include "complex.h"

#define MIN_NUMBER      1e-15

class CalculateFunction
{
public:
    CalculateFunction();
    void clearError();
    bool checkError(QString& message);
    virtual QString getName() = 0;
    virtual QString getInstruction() = 0;
    virtual bool execute(QList<complex> paraList, complex& result, QString& message) = 0;
};

#endif // CALCULATORFUNCTION_H
