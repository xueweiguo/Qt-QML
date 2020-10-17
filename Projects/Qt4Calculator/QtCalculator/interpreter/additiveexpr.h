#ifndef ADDITIVEEXPR_H
#define ADDITIVEEXPR_H

#include"nonterminalexpr.h"

class AdditiveExpr : public NonterminalExpr
{
public:
    AdditiveExpr();
    virtual ~AdditiveExpr();
    static Expr* buildExpr(BuildContext& context);
    virtual ValueOperator* getValueOperator(QString operatorContent);
};

#endif // ADDITIVEEXPR_H
