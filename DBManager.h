#pragma once
#include <QObject>
#include <QVector>

#include "CustomTypes.h"

class DBManager
{
public:
    DBManager();
    ~DBManager();

    void init();
    void setData(QString studentName, int raiting);
    type::CourseResult getBackElem();
    QVector<type::CourseResult> getAllData();

private:
};
