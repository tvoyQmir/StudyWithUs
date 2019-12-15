#include "MaterialContext.h"

class MaterialContextData : public QSharedData
{
public:

};

MaterialContext::MaterialContext() : data(new MaterialContextData)
{

}

MaterialContext::MaterialContext(const MaterialContext &rhs) : data(rhs.data)
{

}

MaterialContext &MaterialContext::operator=(const MaterialContext &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

MaterialContext::~MaterialContext()
{

}
