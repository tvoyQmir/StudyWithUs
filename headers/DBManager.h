#pragma once
#include <QObject>
#include <QVector>

#include "CustomTypes.h"

class DBManager
{
public:
    DBManager();
    ~DBManager();

    void init();

    // Accounts
    void setDataIntoAccounts(const QString& login, const QString& password, const QString studentName);
    void updateRatingOfActiveAccount(const int rating);
    type::Account getLastElemFromAccounts();
    QVector<type::Account> getAllDataFromAccounts();
    QVector<type::Result> getAllResults();
    bool checkData(const QString& login, const QString& password);
    bool isExistInAccountsTable(const QString& login);
    const QString getActiveAccount();
    bool checkActiveAdminAccont();

private:
    type::Account m_ActiveAccount;
};
