#include <QtSql>

#include "headers/DBManager.h"

DBManager::DBManager()
{
    qDebug() << "DBManager::DBManager";
}

DBManager::~DBManager()
{
    qDebug() << "DBManager::~DBManager";
}

void DBManager::init()
{
    qDebug() << "DBManager::init";

    // need to check if DB exists

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open())
    {
        qDebug() << "Something went wrong!! Can't open data base.";
        return ;
    }

    QSqlQuery a_query;

    QString str = "CREATE TABLE Accounts(id integer PRIMARY KEY NOT NULL, login VARCHAR(255), password VARCHAR(255), name VARCHAR(255), rating integer);";

    if (!a_query.exec(str))
    {
        qDebug() << "Can't create table Accounts";
        return;
    }
    //TODO

}

void DBManager::setDataIntoAccounts(const QString& login, const QString& password, const QString studentName)
{
    qDebug() << "DBManager::setDataIntoAccounts(" << login << ", "<< password << ", " << studentName << ", " << 0 << ")"; // TODO log and pass encryption

    QSqlQuery a_query;

    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return;
    }

    QSqlRecord rec = a_query.record();
    a_query.last();

    const int id = a_query.value(rec.indexOf("id")).toInt() + 1;
    qDebug() << "id is" << id;

    QString str_insert = "INSERT INTO Accounts (id, login, password, name, rating) VALUES (%1, '%2', '%3', '%4', %5);";
    QString str = str_insert.arg(id).arg(QString(login)).arg(QString(password)).arg(studentName).arg(0);

    if (!a_query.exec(str))
    {
        qDebug() << "Cant insert data to table";
        return;
    }

}

void DBManager::updateRatingOfActiveAccount(const int rating)
{
    qDebug() << "DBManager::updateRatingOfActiveAccount(" << rating << ")";

    QString str_update = "UPDATE Accounts SET rating = %1 WHERE id = %2);";
    QString str = str_update.arg(rating).arg(m_ActiveAccount.id);

    QSqlQuery a_query;

    if (!a_query.exec(str))
    {
        qDebug() << "Can't update data from table";
        return;
    }

    m_ActiveAccount.raiting = rating;
}

type::Account DBManager::getLastElemFromAccounts()
{
    qDebug() << "DBManager::getLastElemFromAccounts";

    type::Account account;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return type::Account();
    }

    QSqlRecord rec = a_query.record();

    a_query.last();

    account.id = a_query.value(rec.indexOf("id")).toInt();
    account.login = QString(a_query.value(rec.indexOf("login")).toString().toStdString().c_str());
    account.password = QString(a_query.value(rec.indexOf("password")).toString().toStdString().c_str());
    account.studentName = a_query.value(rec.indexOf("name")).toString();
    account.raiting = a_query.value(rec.indexOf("rating")).toInt();


    qDebug() << "account: " << account.id << ", " <<  account.login << ", " << account.password << ", " << account.studentName << ", " << account.raiting;

    return account;
}

QVector<type::Account> DBManager::getAllDataFromAccounts()
{
    qDebug() << "DBManager::getAllDataFromAccounts()";

    QVector<type::Account> accounts;
    type::Account account;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return QVector<type::Account>();
    }

    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {
        const int id = a_query.value(rec.indexOf("id")).toInt();
        const QString login(a_query.value(rec.indexOf("login")).toString().toStdString().c_str());
        const QString password = a_query.value(rec.indexOf("password")).toString().toStdString().c_str();
        const QString studName = a_query.value(rec.indexOf("name")).toString();
        const int raiting = a_query.value(rec.indexOf("rating")).toInt();

        qDebug() << "| id is " <<  id
                 << "| login is " << login
                 << "| password is " << password
                 << "| name is " << studName
                 << "| raiting is " << raiting
                 << "|";

        account.id = id;
        account.login = login;
        account.password = password;
        account.studentName = studName;
        account.raiting = raiting;
        accounts.push_back(account);
    }

    return accounts;
}

QVector<type::Result> DBManager::getAllResults()
{
    qDebug() << "DBManager::getAllResults()";
    QVector<type::Result> results;
    type::Result result;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT name, rating FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return QVector<type::Result>();
    }

    QSqlRecord rec = a_query.record();

    while (a_query.next())
    {

        const QString studName = a_query.value(rec.indexOf("name")).toString();
        const int raiting = a_query.value(rec.indexOf("rating")).toInt();

        qDebug() << "| name is " << studName
                 << "| raiting is " << raiting
                 << "|";


        result.studentName = studName;
        result.raiting = raiting;
        results.push_back(result);
    }

    return results;
}

bool DBManager::checkData(const QString& login, const QString& password)
{
    qDebug() << "DBManager::checkData()";

    const QVector<type::Account> accounts = this->getAllDataFromAccounts();

    bool succes = false;

    foreach(const auto& account, accounts)
    {
        if (account.login.toStdString() == login.toStdString() && account.password.toStdString() == password.toStdString())
        {
            succes = true;
            m_ActiveAccount = account;
        }
    }

    return succes;
}

bool DBManager::isExistInAccountsTable(const QString& login)
{
    qDebug() << "DBManager::findInAccountsTable(" << login << ")";

    const QVector<type::Account> accounts = this->getAllDataFromAccounts();

    bool existInDB = false;

    foreach(const auto& account, accounts)
    {
        if (account.login == QString(login))
        {
           qDebug() << "Such login already exists";
           existInDB = true;
        }
    }

    return existInDB;
}

const QString DBManager::getActiveAccount()
{
    qDebug() << "DBManager::getActiveAccount";
    return QString(m_ActiveAccount.login.toStdString().c_str()); // TODO get all account
}

bool DBManager::checkActiveAdminAccont()
{
    qDebug() << "DBManager::checkActiveAdminAccont";

    const type::AdminAccount admin;
    bool isAdmin = false;

    if (admin.login == m_ActiveAccount.login)
    {
        isAdmin = true;
    }

    return isAdmin;
}
