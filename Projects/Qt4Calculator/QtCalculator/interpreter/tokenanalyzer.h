#ifndef TOKENANALYZER_H
#define TOKENANALYZER_H

#include<QString>
#include<QList>
#include<QRegExp>

template<typename Token, typename TokenType, typename TokenIterator>
class TokenAnalyzer
{
public:
    struct TokenPattern
    {
        TokenPattern(TokenType _type, QString _regex):regex(_regex),type(_type){}
        QRegExp regex;
        TokenType type;
    };

    class TokenPatternFactory
    {
    public:
        virtual int createPatterns(QList<TokenPattern*>& list) const= 0;
    };

    TokenAnalyzer(){}
    QList<Token*> analyzeToken(QString strInput, const TokenPatternFactory* factory);
private:
    struct Context
    {
        Context(QList<Token*>& list, TokenIterator& _it, TokenPattern* _pattern, QString& _content)
            :tokenList(list), it(_it), pattern(_pattern), content(_content){}
        QList<Token*>& tokenList;
        TokenIterator& it;
        TokenPattern* pattern;
        QString& content;
    };
    void analyzeContent(Context& context);
};

template<typename Token, typename TokenType, typename TokenIterator>
QList<Token*> TokenAnalyzer<Token, TokenType, TokenIterator>::analyzeToken(QString strInput, const TokenPatternFactory* factory)
{
    QList<Token*> tokenList;

    tokenList.append(new Token(strInput));

    QList<TokenPattern*> list;
    factory->createPatterns(list);

    foreach(TokenPattern* pattern, list)
    {
        TokenIterator it = tokenList.begin();
        while(it != tokenList.end())
        {
            Token* token = *it;
            if(token->isNoType())
            {
                QString content = token->getContent();
                Context context(tokenList, it, pattern, content);
                analyzeContent(context);
            }
            it++;
        }
    }
    qDeleteAll(list);
    return tokenList;
}

template<typename Token, typename TokenType, typename TokenIterator>
void TokenAnalyzer<Token, TokenType, TokenIterator>::analyzeContent(Context& context)
{
    Token* token = *context.it;
    int tokenBegin = context.content.indexOf(context.pattern->regex);
    if(tokenBegin != -1)
    {
        int matchedLength = context.pattern->regex.matchedLength();
        int tokenEnd = tokenBegin + matchedLength;
        if(tokenBegin > 0)
        {
            context.it = context.tokenList.insert(context.it, new Token(context.content.left(tokenBegin)));
            context.it++;
        }
        if(tokenEnd < context.content.length())
        {
            context.it = context.tokenList.insert(context.it,
                         new Token(context.pattern->type, context.content.mid(tokenBegin, matchedLength)));
            context.it++;
            context.content.remove(0, tokenEnd);
            analyzeContent(context);
        }
        else
        {
            token->setContent(context.content.mid(tokenBegin, tokenEnd));
            token->setType(context.pattern->type);
            context.content.remove(0, tokenEnd);
        }
    }
    else
    {
        token->setContent(context.content);
    }
}


#endif // TOKENANALYZER_H
