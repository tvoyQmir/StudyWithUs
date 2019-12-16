#pragma once
#include <QObject>
#include <QVector>
#include "Types.h"

class DBManager
{
public:
    DBManager();
    ~DBManager();

private:
    void init();
    void setData(QString studentName, int raiting);
    type::CourseResult getBackElem();
    QVector<type::CourseResult> getAllData();
};
