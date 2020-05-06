#include <QDebug>

#include "headers/fileoperations.h"

FileOperations::FileOperations()
    : m_file("/Users/arturchechui/git/StudyWithUs/text/test.txt")
{
    qDebug() << "FileOperations::FileOperations";
}

void FileOperations::init()
{
    qDebug() << "FileOperations::init";
    // TODO
}

QStringList FileOperations::getText(type::eSubject subject)
{

    qDebug() << "FileOperations::getText(" << static_cast<int>(subject) << ")";
/*
    switch (subject)
    {
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {
        //return readFile(type::g_firstSubjectKeyStarts, type::g_firstSubjectKeyEnds);
        break;
    }
    case type::eSubject::SHAPES_AND_THEIR_ELEMENTS:
    {
        //return readFile(type::g_secondtSubjectKeyStarts, type::g_secondSubjectKeyEnds);
        break;
    }
    case type::eSubject::BASIC_THEOREMS_OF_INITIAL_GEOMENTRY:
    {
        //return readFile(type::g_thirdSubjectKeyStarts, type::g_thirdSubjectKeyEnds);
        break;
    }
    default:
        qDebug() << "Unexpected type";
        return QStringList();
        break;
    }
    */
    QStringList list;
    list.append("test");
    return list;
}

QStringList FileOperations::readFile(const QString& strKeyStarts, const QString& strKeyEnds)
{
    qDebug() << "FileOperations::readFile()";

    QStringList strList;
    bool needToWriteToStrList = false;

    if (m_file.exists() && m_file.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&m_file);
        textStream.setCodec("UTF-8");

        qDebug() << "Start reading";

        while (!textStream.atEnd())
        {
            const QString line(textStream.readLine());

            if (line == strKeyStarts)
            {
                qDebug() << "*** found key :" << line << ", needToWriteToStr true";
                needToWriteToStrList = true;
                continue;
            }
            else if (line == strKeyEnds)
            {
                qDebug() << "*** found key :" << line << ", needToWriteToStr false";
                needToWriteToStrList = false;
                continue;
            }

            qDebug() << line;

            if (needToWriteToStrList)
            {
                strList.push_back(line);
            }
        }

        qDebug() << "End reading";
    }
    else
    {
        qDebug() << "Something went wrong! File does not exist or can't open";
    }

    m_file.close();

    foreach(const auto& line, strList)
    {
         qDebug() << line;
    }

    return strList;
}
