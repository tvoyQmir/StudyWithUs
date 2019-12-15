#include "Facade.h"

class FacadeData : public QSharedData
{
public:

};

Facade::Facade() : data(new FacadeData)
{

}

Facade::Facade(const Facade &rhs) : data(rhs.data)
{

}

Facade &Facade::operator=(const Facade &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Facade::~Facade()
{

}
