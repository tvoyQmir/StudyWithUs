#pragma once
#include <QObject>
#include <QSharedPointer>

#include "MaterialContext.h"
#include "CourseControler.h"
#include "CustomTypes.h"

class DBManager;
class FileOperations;

class Facade
{
public:
    Facade();
    ~Facade();
    void init();

    // Accounts
    void setDataIntoAccounts(const QString& login, const QString& password, const QString studentName);
    type::Account getLastElemFromAccounts() const;
    QVector<type::Account> getAllDataFromAccounts() const;
    QVector<type::Result> getAllResults() const;
    bool checkData(const QString& login, const QString& password);
    bool isExistInAccountsTable(const QString& login);
    const QString getActiveAccount(); // TODO
    bool checkActiveAdminAccont();

    //FileOperations
    QStringList getText(type::eSubject subject);
    bool saveText(const QStringList& strList);

private:
    QSharedPointer<DBManager> m_DBManager;
    QSharedPointer<FileOperations> m_FileOperations;
    MaterialContext m_MaterialContext;
    CourseControler m_CourseControler;
};
