#pragma once
#include <QObject>
#include <QSharedPointer>

class DBManager;

class MaterialContext
{
public:
    MaterialContext(QSharedPointer<DBManager> DBManager);
    ~MaterialContext();
    void init();

private:
    QSharedPointer<DBManager> m_DBManager;
};
