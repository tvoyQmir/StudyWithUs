#pragma once
#include <QObject>
#include <QSharedDataPointer>

class CourseControlerData;

class CourseControler
{
public:
    CourseControler();
    CourseControler(const CourseControler &);
    CourseControler &operator=(const CourseControler &);
    ~CourseControler();

private:
    QSharedDataPointer<CourseControlerData> data;
};
