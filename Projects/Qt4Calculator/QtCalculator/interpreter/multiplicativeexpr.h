#ifndef MULTIPLICATIVEEXPR_H
#define MULTIPLICATIVEEXPR_H

#include"nonterminalexpr.h"

class MultiplicativeExpr : public NonterminalExpr
{
public:
    MultiplicativeExpr();
    ~MultiplicativeExpr();
    static Expr* buildExpr(BuildContext& context);
    virtual ValueOperator* getValueOperator(QString operatorContent);
};

#endif // MULTIPLICATIVEEXPR_H
