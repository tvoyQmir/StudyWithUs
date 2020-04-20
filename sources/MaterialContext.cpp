#include <QDebug>

#include "headers/MaterialContext.h"
#include "headers/fileoperations.h"
#include "headers/DBManager.h"

MaterialContext::MaterialContext(QSharedPointer<DBManager> DBManager, QSharedPointer<FileOperations> FileOperations)
    : m_DBManager(DBManager)
    , m_FileOperations(FileOperations)
{
    qDebug() << "MaterialContext::MaterialContext";
}

MaterialContext::~MaterialContext()
{
    qDebug() << "MaterialContext::~MaterialContext";
}

void MaterialContext::init()
{
    qDebug() << "MaterialContext::init";
}
