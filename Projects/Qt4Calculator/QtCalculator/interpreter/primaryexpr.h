#ifndef PRIMARYEXPR_H
#define PRIMARYEXPR_H

#include"terminalexpr.h"

class PrimaryExpr : public TerminalExpr
{
public:
    PrimaryExpr();
    static Expr* buildExpr(BuildContext& context);
};

#endif // PRIMARYEXPR_H
