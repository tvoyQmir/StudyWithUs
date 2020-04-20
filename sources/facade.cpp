#include <QDebug>

#include "headers/Facade.h"
#include "headers/DBManager.h"
#include "headers/fileoperations.h"

Facade::Facade()
    : m_DBManager(new DBManager)
    , m_FileOperations(new FileOperations)
    , m_MaterialContext(m_DBManager, m_FileOperations)
    , m_CourseControler(m_DBManager, m_FileOperations)
{
    qDebug() << "Facade::Facade()";
}

Facade::~Facade()
{
    qDebug() << "Facade::~Facade()";
}

void Facade::init()
{
    qDebug() << "Facade::init()";

     m_DBManager->init();
     m_FileOperations->init();
     m_MaterialContext.init();
     m_CourseControler.init();
}

void Facade::setDataIntoAccounts(const QString& login, const QString& password, const QString studentName)
{
     qDebug() << "Facade::setDataIntoAccounts(" << login << password << studentName << ")";
     m_DBManager->setDataIntoAccounts(login, password, studentName);
}

type::Account Facade::getLastElemFromAccounts() const
{
     qDebug() << "Facade::getLastElemFromAccounts()";
     return m_DBManager->getLastElemFromAccounts();
}

QVector<type::Account> Facade::getAllDataFromAccounts() const
{
     qDebug() << "Facade::getAllDataFromAccounts()";
     return m_DBManager->getAllDataFromAccounts();
}

bool Facade::checkData(const QString& login, const QString& password)
{
     qDebug() << "Facade::checkData(" << login << password <<")";
     return m_DBManager->checkData(login, password);
}

bool Facade::isExistInAccountsTable(const QString& login)
{
     qDebug() << "Facade::isExistInAccountsTable(" << login << ")";
     return m_DBManager->isExistInAccountsTable(login);
}

const QString Facade::getActiveAccount()
{
     qDebug() << "Facade::getActiveAccount()";
     return m_DBManager->getActiveAccount();
}

QStringList Facade::getText(int subject)
{
     qDebug() << "Facade::requestText(" << subject << ")";
     return m_FileOperations->getText(subject);
}
