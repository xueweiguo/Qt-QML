#ifndef TOKEN_H
#define TOKEN_H

#include<QString>
#include<QRegExp>
#include<QList>

class Token
{
public:
    enum EType
    {
        NoType,
        Operator,
        Parenthese,
        Comma,
        Number,
        FunctionName
    };

    Token(EType type, QString content);
    Token(QString content);
    virtual ~Token();
    EType getType();
    QString getContent();

    void setType(EType type);
    bool isNoType();
    void setContent(QString content);

private:
    EType mType;
    QString mContent;
};

#endif // TOKEN_H
