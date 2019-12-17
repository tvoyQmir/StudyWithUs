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
    QString str = "CREATE TABLE CourseResults (ID integer PRIMARY KEY NOT NULL, StudentName VARCHAR(255), Rating integer);";
    bool b = a_query.exec(str);
    if (!b)
    {
        qDebug() << "Can't create table";
    }
}

void DBManager::setData(QString studentName, int raiting)
{
    qDebug() << "DBManager::setData(" << studentName << raiting << ")";

    QSqlQuery a_query;
    QString str_insert = "INSERT INTO CourseResults (ID, StudentName, Rating) VALUES (%1, '%2', %3);";

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

type::CourseResult DBManager::getBackElem()
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
        courseResult.id = a_query.value(rec.indexOf("ID")).toInt();
        courseResult.studentName = a_query.value(rec.indexOf("StudentName")).toString();
        courseResult.raiting = a_query.value(rec.indexOf("Rating")).toInt();

        qDebug() << "id is " << courseResult.id << ". studentName is " <<  courseResult.studentName << ". raiting = " << courseResult.raiting;
    }

    return courseResult;
}

QVector<type::CourseResult> DBManager::getAllData()
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
            courseResult[count].id = a_query.value(rec.indexOf("ID")).toInt();
            courseResult[count].studentName = a_query.value(rec.indexOf("StudentName")).toString();
            courseResult[count].raiting = a_query.value(rec.indexOf("Rating")).toInt();
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
