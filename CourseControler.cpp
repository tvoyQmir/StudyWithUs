#include <QDebug>

#include "CourseControler.h"

CourseControler::CourseControler(QSharedPointer<DBManager> DBManager)
    : m_DBManager(DBManager)
{
    qDebug() << "CourseControler::CourseControler";
}

CourseControler::~CourseControler()
{
    qDebug() << "CourseControler::~CourseControler";
}

void CourseControler::init()
{
    qDebug() << "CourseControler::init";
    //TODO
}
