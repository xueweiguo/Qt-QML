#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include<QMap>
#include<QList>
#include<calculatefunction.h>

class FunctionManager
{
public:
    class FunctionRegister
    {
    public:
        FunctionRegister(CalculateFunction* fun)
        {
            FunctionManager::getInstance()->registerFunction(fun);
        }
    };

    static FunctionManager* getInstance();
    static void clearInstance();

    bool registerFunction(CalculateFunction* fun);
    QList<QString> functions() const;
    CalculateFunction* getFunction(QString name);
private:
    FunctionManager();
    FunctionManager(FunctionManager& /*manager*/){}
    ~FunctionManager();

    static FunctionManager* m_singleManager;
    QMap<QString, CalculateFunction*> m_functionMap;
};

#endif // FUNCTIONMANAGER_H
