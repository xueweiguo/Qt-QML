#ifndef UNARYEXPR_H
#define UNARYEXPR_H

#include "terminalexpr.h"

class UnaryExpr : public TerminalExpr
{
public:
    UnaryExpr();
    ~UnaryExpr();
    void setPrimaryExpr(Expr* expr);
    static Expr* buildExpr(BuildContext& context);
    virtual bool evaluate(EvalulateContext& context);
private:
    Expr* primaryExpr;
};

#endif // UNARYEXPR_H
