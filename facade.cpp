#include <QDebug>

#include "Facade.h"

Facade::Facade()
    : m_DBManager(new DBManager)
    , m_MaterialContext(m_DBManager)
    , m_CourseControler(m_DBManager)
{
    qDebug() << "Facade::Facade";
}

Facade::~Facade()
{
    qDebug() << "Facade::~Facade";
}

void Facade::init()
{
    qDebug() << "Facade::init";

    m_DBManager->init();
    m_MaterialContext.init();
    m_CourseControler.init();
}
