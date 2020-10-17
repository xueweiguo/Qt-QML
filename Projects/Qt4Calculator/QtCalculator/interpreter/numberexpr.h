#ifndef NUMBEREXPR_H
#define NUMBEREXPR_H

#include"terminalexpr.h"

class NumberExpr : public TerminalExpr
{
public:
    NumberExpr();
    ~NumberExpr();
    void setValueString(QString value);
    virtual bool evaluate(EvalulateContext& context);
private:
    QString valueString;
};

#endif // NUMBEREXPR_H
