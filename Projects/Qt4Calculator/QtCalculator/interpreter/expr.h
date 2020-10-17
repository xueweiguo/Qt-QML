#ifndef EXPR_H
#define EXPR_H

#include<QList>
#include<QString>
#include"token.h"
#include"complex.h"

#include <QtDebug>

class Expr
{
public:
    struct BuildContext
    {
        BuildContext(QList<Token*>& list):tokenList(list){}
        QList<Token*>& tokenList;
        QString errorMessage;
    };

    struct EvalulateContext
    {
        EvalulateContext(){resultStack.append(0);}
        QList<complex> resultStack;
        QString errorMessage;
    };

    Expr(){}
    virtual ~Expr(){}
    virtual bool evaluate(EvalulateContext& context) = 0;
};

#endif // EXPR_H
