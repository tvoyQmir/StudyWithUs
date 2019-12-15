#pragma once
#include <QObject>
#include <QSharedDataPointer>

class MaterialContextData;

class MaterialContext
{
public:
    MaterialContext();
    MaterialContext(const MaterialContext &);
    MaterialContext &operator=(const MaterialContext &);
    ~MaterialContext();

private:
    QSharedDataPointer<MaterialContextData> data;
};
