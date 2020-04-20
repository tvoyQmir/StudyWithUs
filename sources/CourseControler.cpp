#include <QDebug>

#include "headers/CourseControler.h"
#include "headers/DBManager.h"
#include "headers/fileoperations.h"

CourseControler::CourseControler(QSharedPointer<DBManager> DBManager, QSharedPointer<FileOperations> FileOperations)
    : m_DBManager(DBManager)
    , m_FileOperations(FileOperations)
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
