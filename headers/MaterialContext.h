#pragma once
#include <QObject>
#include <QSharedPointer>

class DBManager;
class FileOperations;

class MaterialContext
{
public:
    MaterialContext(QSharedPointer<DBManager> DBManager, QSharedPointer<FileOperations> FileOperations);
    ~MaterialContext();
    void init();

private:
    QSharedPointer<DBManager> m_DBManager;
    QSharedPointer<FileOperations> m_FileOperations;
};
