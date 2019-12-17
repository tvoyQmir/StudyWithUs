#pragma once
#include <QObject>
#include <QSharedPointer>

class DBManager;

class CourseControler
{
public:
    CourseControler(QSharedPointer<DBManager> DBManager);
    ~CourseControler();
    void init();

private:
    QSharedPointer<DBManager> m_DBManager;
};
