#pragma once
#include <QObject>

namespace type
{
struct CourseResult
{
    int id;
    QString studentName;
    int raiting;
};

struct Account
{
   int id;
   QString login;
   QString password;
};

struct EducationMaterial
{
    int id;
    QString topic;
    QString data;
    int complexity;
};

struct Task
{
    int id;
    QString topic;
    QString data;
    int complexity;
};
}//namespace type
