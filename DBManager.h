#pragma once
#include <QObject>
#include <QSharedDataPointer>

class DBManagerData;

class DBManager
{
public:
    DBManager();
    DBManager(const DBManager &);
    DBManager &operator=(const DBManager &);
    ~DBManager();

private:
    QSharedDataPointer<DBManagerData> data;
};
