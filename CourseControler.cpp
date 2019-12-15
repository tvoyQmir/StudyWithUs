#include "CourseControler.h"

class CourseControlerData : public QSharedData
{
public:

};

CourseControler::CourseControler() : data(new CourseControlerData)
{

}

CourseControler::CourseControler(const CourseControler &rhs) : data(rhs.data)
{

}

CourseControler &CourseControler::operator=(const CourseControler &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

CourseControler::~CourseControler()
{

}
