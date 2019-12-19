#pragma once
#include <QObject>
#include <QSharedPointer>
#include "MaterialContext.h"
#include "CourseControler.h"
#include "DBManager.h"

class Facade
{
public:
    Facade();
    ~Facade();
    void init();

    // Accounts
    void setDataIntoAccounts(QString login, QString password);
    type::Account getLastElemFromAccounts() const;
    QVector<type::Account> getAllDataFromAccounts() const;

private:
    QSharedPointer<DBManager> m_DBManager;
    MaterialContext m_MaterialContext;
    CourseControler m_CourseControler;
};
