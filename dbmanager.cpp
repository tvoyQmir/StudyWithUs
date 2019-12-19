#include <QtSql>

#include "DBManager.h"

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

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open())
    {
        qDebug() << "Something went wrong!! Can't open data base.";
        return ;
    }

    QSqlQuery a_query;

    // DDL query
    /*QString str = "CREATE TABLE CourseResults (id integer PRIMARY KEY NOT NULL, name VARCHAR(255), rating integer);";
    bool b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Can't create table CourseResults";
        return;
    }
    */
    QString str = "CREATE TABLE Accounts (id integer PRIMARY KEY NOT NULL, login VARCHAR(255), password VARCHAR(255));";
    bool b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Can't create table Accounts";
        return;
    }

   /* str = "CREATE TABLE EducationMaterial (id integer PRIMARY KEY NOT NULL, topic VARCHAR(255), data VARCHAR(255), complexity integer);";
    b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Can't create table EducationMaterial";
        return;
    }

    str = "CREATE TABLE Tasks (id integer PRIMARY KEY NOT NULL, topic VARCHAR(255), data VARCHAR(255), complexity integer);";
    b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Can't create table Tasks";
        return;
    }
    */
}

void DBManager::setDataIntoCourseResults(QString studentName, int raiting)
{
    qDebug() << "DBManager::setData(" << studentName << raiting << ")";

    QSqlQuery a_query;
    QString str_insert = "INSERT INTO CourseResults (id, name, rating) VALUES (%1, '%2', %3);";

    //TODO: generate ID
    QString str = str_insert.arg("1")
            .arg(studentName)
            .arg(raiting);

    bool b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Cant insert data to table";
    }
}

type::CourseResult DBManager::getLastElemFromCourseResults()
{
    qDebug() << "DBManager::getBackElem";

    type::CourseResult courseResult;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM CourseResults"))
    {
        qDebug() << "Can't select data from table";
        return type::CourseResult(); // TODO: need default data
    }

    QSqlRecord rec = a_query.record();

    while (a_query.last())
    {
        courseResult.id = a_query.value(rec.indexOf("id")).toInt();
        courseResult.studentName = a_query.value(rec.indexOf("name")).toString();
        courseResult.raiting = a_query.value(rec.indexOf("rating")).toInt();

        qDebug() << "id is " << courseResult.id << ". studentName is " <<  courseResult.studentName << ". raiting = " << courseResult.raiting;
    }

    return courseResult;
}

QVector<type::CourseResult> DBManager::getAllDataFromCourseResults()
{
    qDebug() << "DBManager::getAllData";

    QVector<type::CourseResult> courseResult;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM CourseResults"))
    {
        qDebug() << "Can't select data from table";
        return QVector<type::CourseResult>(); // TODO: need default data
    }

    QSqlRecord rec = a_query.record();

    courseResult.resize(a_query.size());
    int count = 0;
    while (a_query.next())
    {
        if (count < courseResult.size())
        {
            courseResult[count].id = a_query.value(rec.indexOf("id")).toInt();
            courseResult[count].studentName = a_query.value(rec.indexOf("name")).toString();
            courseResult[count].raiting = a_query.value(rec.indexOf("rating")).toInt();
            ++count;
            qDebug() << "id is " <<  courseResult[count].id << ". studentName is " <<  courseResult[count].studentName << ". raiting = " << courseResult[count].raiting;
        }
        else
        {
           qDebug() << "count > courseResult.size()";
        }
    }

    return courseResult;
}

void DBManager::setDataIntoAccounts(QString login, QString password)
{
    qDebug() << "DBManager::setDataIntoAccounts(" << login << password << ")"; // TODO log and pass encryption

    QSqlQuery a_query;
    QString str_insert = "INSERT INTO Accounts (id, login, password) VALUES (%1, '%2', '%3');";

    //TODO: generate ID
    int id = 1;

    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
    }

    QSqlRecord rec = a_query.record();

    a_query.last();
    id = a_query.value(rec.indexOf("id")).toInt() + 1;
    qDebug() << id;

    QString str = str_insert.arg(id).arg(login).arg(password);
    bool b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Cant insert data to table";
    }
}

type::Account DBManager::getLastElemFromAccounts()
{
    qDebug() << "DBManager::getLastElemFromAccounts";

    type::Account account;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return type::Account(); // TODO: need default data
    }

    QSqlRecord rec = a_query.record();

    a_query.last();

    account.id = a_query.value(rec.indexOf("id")).toInt();
    account.login = a_query.value(rec.indexOf("login")).toString();
    account.password = a_query.value(rec.indexOf("password")).toString();

    qDebug() << "id is " << account.id << ". studentName is " <<  account.login << ". raiting = " << account.password;

    return account;
}

QVector<type::Account> DBManager::getAllDataFromAccounts()
{

    qDebug() << "DBManager::getAllDataFromAccounts";

    QVector<type::Account> accounts;

    QSqlQuery a_query;
    if (!a_query.exec("SELECT * FROM Accounts"))
    {
        qDebug() << "Can't select data from table";
        return QVector<type::Account>(); // TODO: need default data
    }

    QSqlRecord rec = a_query.record();

    if (0 < a_query.size())
    {
        accounts.resize(a_query.size());
    }
    else
    {
        qDebug() << "a_query is null";
        return QVector<type::Account>();
    }

    int count = 0;
    while (a_query.next())
    {
        if (count < accounts.size())
        {
            accounts[count].id = a_query.value(rec.indexOf("id")).toInt();
            accounts[count].login = a_query.value(rec.indexOf("login")).toString();
            accounts[count].password = a_query.value(rec.indexOf("password")).toString();
            qDebug() << "id is " <<  accounts[count].id << ". studentName is " <<  accounts[count].login << ". raiting = " << accounts[count].password;
            ++count;
        }
        else
        {
           qDebug() << "count > courseResult.size()";
        }
    }

    return accounts;
}

void DBManager::setDataIntoEducationMaterial(QString topic, QString data, int complexity)
{
    qDebug() << topic << data << complexity;
}

type::EducationMaterial DBManager::getLastElemFromEducationMaterial()
{
    return type::EducationMaterial();
}

QVector<type::EducationMaterial> DBManager::getAllDataFromEducationMaterial()
{
    return QVector<type::EducationMaterial>();
}

void DBManager::setDataIntoTasks(QString topic, QString data, int complexity)
{
    qDebug() << topic << data << complexity;
}

type::Task DBManager::getLastElemFromTasks()
{
    return type::Task();
}

QVector<type::Task> DBManager::getAllDataFromTasks()
{
    return QVector<type::Task>();
}
