#pragma once
#include <QFile>

#include "headers/CustomTypes.h"

class FileOperations
{
public:

    FileOperations();
    void init();
    QStringList getText(type::eSubject subject);

private:
    QStringList readFile(const QString& strKeyStarts, const QString& strKeyEnds);
    QFile m_file;
};
