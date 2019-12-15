#pragma once
#include <QObject>
#include <QSharedDataPointer>

class FacadeData;

class Facade
{
public:
    Facade();
    Facade(const Facade &);
    Facade &operator=(const Facade &);
    ~Facade();

private:
    QSharedDataPointer<FacadeData> data;
};
