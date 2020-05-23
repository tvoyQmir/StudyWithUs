#pragma once
#include <QFile>

#include "headers/CustomTypes.h"

class FileOperations
{
public:

    FileOperations();
    void init();
    QStringList getText(type::eSubject subject);
    bool saveText(const QStringList& strList);

private:
    QStringList readFile(const QString& strKeyStarts, const QString& strKeyEnds);
    QStringList clearFromServiceInformation(const QStringList& stringList);

    QFile m_file;
};
