#pragma once
#include <QObject>

namespace type
{

struct Account
{
   int id;
   QString login;
   QString password;
   QString studentName;
   int raiting;
};

 enum eSubject : int
{
    MIN = 0,
    THE_SIMPLEST_GEOMETRY_OBJECTS,
    SHAPES_AND_THEIR_ELEMENTS,
    BASIC_THEOREMS_OF_INITIAL_GEOMENTRY,
    MAX
};

//const QString g_firstSubjectKeyStarts = "firstSubjectKeyStarts";
//const QString g_firstSubjectKeyEnds = "firstSubjectKeyEnds";
//const QString g_secondtSubjectKeyStarts = "secondtSubjectKeyStarts";
//const QString g_secondSubjectKeyEnds = "secondSubjectKeyEnds";
//const QString g_thirdSubjectKeyStarts = "thirdSubjectKeyStarts";
//const QString g_thirdSubjectKeyEnds = "thirdSubjectKeyEnds";

} //namespace type
