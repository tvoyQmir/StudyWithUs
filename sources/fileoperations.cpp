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

    switch (subject)
    {
    case type::eSubject::ALL_TEXT:
    {
        return readFile(type::g_KeyStarts, type::g_KeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS:
    {
        return readFile(type::g_firstSubjectKeyStarts, type::g_firstSubjectKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_TITLE:
    {
        return readFile(type::g_firstSubjectTitleKeyStarts, type::g_firstSubjectTitleKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_DOT:
    {
        return readFile(type::g_firstSubjectDotKeyStarts, type::g_firstSubjectDotKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_LINE:
    {
        return readFile(type::g_firstSubjectLineKeyStarts, type::g_firstSubjectLineKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_BEAM:
    {
        return readFile(type::g_firstSubjectBeamKeyStarts, type::g_firstSubjectBeamKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_LINE_SEG:
    {
        return readFile(type::g_firstSubjectLineSegKeyStarts, type::g_firstSubjectLineSegKeyEnds);
        break;
    }
    case type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS_ANGLED_LINE:
    {
        return readFile(type::g_firstSubjectAngledLineKeyStarts, type::g_firstSubjectAngledLineKeyEnds);
        break;
    }
    case type::eSubject::SHAPES_AND_THEIR_ELEMENTS:
    {
        return readFile(type::g_secondtSubjectKeyStarts, type::g_secondSubjectKeyEnds);
        break;
    }
    case type::eSubject::BASIC_THEOREMS_OF_INITIAL_GEOMENTRY:
    {
        return readFile(type::g_thirdSubjectKeyStarts, type::g_thirdSubjectKeyEnds);
        break;
    }
    case type::eSubject::MIN:
    case type::eSubject::MAX:
    default:
        qDebug() << "Unexpected type";
        return QStringList();
        break;
    }
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
                qDebug() << "*** found key :" << line << ", needToWriteToStrList true";
                needToWriteToStrList = true;
                continue;
            }
            else if (line == strKeyEnds)
            {
                qDebug() << "*** found key :" << line << ", needToWriteToStrList false";
                needToWriteToStrList = false;
                break;
            }

            //qDebug() << line;

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
/*
    foreach(const auto& line, strList)
    {
         qDebug() << line;
    }
*/
    return clearFromServiceInformation(strList);
}

QStringList FileOperations::clearFromServiceInformation(const QStringList& stringList)
{
    qDebug() << "FileOperations::clearFromServiceInformation()";

    bool needToWriteToStrList;
    QStringList stringListToUI;

    foreach(const auto& line, stringList)
    {
        needToWriteToStrList = true;

        if (line.indexOf(type::g_KeyStarts) != -1)
        {
            needToWriteToStrList = false;
        }
        else if (line.indexOf(type::g_KeyEnds) != -1)
        {
            needToWriteToStrList = false;
        }

        if (needToWriteToStrList)
        {
            stringListToUI.push_back(line);
            //qDebug() << line;
        }
    }

    return stringListToUI;
}
