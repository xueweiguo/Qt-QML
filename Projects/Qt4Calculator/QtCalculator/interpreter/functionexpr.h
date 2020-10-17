#ifndef FUNCTIONEXPR_H
#define FUNCTIONEXPR_H

#include"nonterminalexpr.h"

class FunctionExpr : public NonterminalExpr
{
public:
    FunctionExpr(QString name);
    ~FunctionExpr();
    static Expr* buildExpr(BuildContext& context);
    virtual bool evaluate(EvalulateContext& context);
private:
    QString functionName;
};

#endif // FUNCTIONEXPR_H
