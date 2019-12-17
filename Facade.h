#pragma once
#include <QObject>
#include <QSharedPointer>
#include "MaterialContext.h"
#include "CourseControler.h"
#include "DBManager.h"

class Facade
{
public:
    Facade();
    ~Facade();
    void init();

private:
    QSharedPointer<DBManager> m_DBManager;
    MaterialContext m_MaterialContext;
    CourseControler m_CourseControler;
};
