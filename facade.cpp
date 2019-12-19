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

void Facade::setDataIntoAccounts(QString login, QString password)
{
    qDebug() << "Facade::setDataIntoAccounts(" << login << password << ")"; // TODO log and pass encryption
    m_DBManager->setDataIntoAccounts(login, password);
}

type::Account Facade::getLastElemFromAccounts() const
{
    qDebug() << "Facade::getLastElemFromAccounts";
    return m_DBManager->getLastElemFromAccounts();
}

QVector<type::Account> Facade::getAllDataFromAccounts() const
{
    qDebug() << "Facade::getAllDataFromAccounts";
    return m_DBManager->getAllDataFromAccounts();
}
