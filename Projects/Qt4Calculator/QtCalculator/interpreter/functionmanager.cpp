#include "functionmanager.h"

#include <QtAlgorithms>

FunctionManager* FunctionManager::m_singleManager = NULL;

FunctionManager* FunctionManager::getInstance()
{
    if(m_singleManager == NULL)
    {
        m_singleManager = new FunctionManager();
    }
    return m_singleManager;
}

void FunctionManager::clearInstance()
{
    if(m_singleManager != NULL){
        delete m_singleManager;
        m_singleManager = NULL;
    }
}

FunctionManager::FunctionManager()
{
}

FunctionManager::~FunctionManager()
{
    qDeleteAll(m_functionMap);
    m_functionMap.clear();
}

bool FunctionManager::registerFunction(CalculateFunction* fun)
{
    if(m_functionMap.find(fun->getName()) == m_functionMap.end())
    {
       m_functionMap.insert(fun->getName(), fun);
       return true;
    }
    else
    {
        return false;
    }
}

QList<QString> FunctionManager::functions() const
{
    return m_functionMap.keys();
}

CalculateFunction* FunctionManager::getFunction(QString name)
{
    return m_functionMap[name];
}
