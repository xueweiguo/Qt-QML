#include "token.h"

#include <QtAlgorithms>
#include "functionmanager.h"

Token::Token(EType type, QString content)
    :mType(type),mContent(content)
{    
}

Token::Token(QString content)
    :mType(NoType),mContent(content)
{
}

Token::~Token()
{
}

Token::EType Token::getType()
{
    return mType;
}

QString Token::getContent()
{
    return mContent;
}

void Token::setType(EType type)
{
    mType = type;
}

void Token::setContent(QString content)
{
    mContent = content;
}

bool Token::isNoType()
{
    return (mType == NoType);
}

