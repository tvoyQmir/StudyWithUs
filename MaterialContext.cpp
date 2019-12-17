#include <QDebug>

#include "MaterialContext.h"

MaterialContext::MaterialContext(QSharedPointer<DBManager> DBManager)
    : m_DBManager(DBManager)
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
    //TODO
}
