#pragma once
#include <QObject>
#include <QSharedPointer>

class DBManager;
class FileOperations;

class CourseControler
{
public:
    CourseControler(QSharedPointer<DBManager> DBManager, QSharedPointer<FileOperations> FileOperations);
    ~CourseControler();
    void init();

private:
    QSharedPointer<DBManager> m_DBManager;
    QSharedPointer<FileOperations> m_FileOperations;
};
