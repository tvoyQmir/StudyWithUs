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

    // CourseResult
    void setDataIntoCourseResults(QString studentName, int raiting);
    type::CourseResult getLastElemFromCourseResults();
    QVector<type::CourseResult> getAllDataFromCourseResults();

    // Accounts
    void setDataIntoAccounts(QString login, QString password);
    type::Account getLastElemFromAccounts();
    QVector<type::Account> getAllDataFromAccounts();

    // EducationMaterial
    void setDataIntoEducationMaterial(QString topic, QString data /*TODO struct for material*/, int complexity);
    type::EducationMaterial getLastElemFromEducationMaterial();
    QVector<type::EducationMaterial> getAllDataFromEducationMaterial();

    // Tasks
    void setDataIntoTasks(QString topic, QString data /*TODO struct for material*/, int complexity);
    type::Task getLastElemFromTasks();
    QVector<type::Task> getAllDataFromTasks();

private:
};
