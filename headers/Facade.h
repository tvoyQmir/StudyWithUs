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
    void setDataIntoAccounts(const QString& login, const QString& password);
    type::Account getLastElemFromAccounts() const;
    QVector<type::Account> getAllDataFromAccounts() const;
    bool checkData(const QString& login, const QString& password);
    bool isExistInAccountsTable(const QString& login);
    QString getActiveAccount(); // TODO

private:
    QSharedPointer<DBManager> m_DBManager;
    MaterialContext m_MaterialContext;
    CourseControler m_CourseControler;
};
