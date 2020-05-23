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

struct Result
{
   QString studentName;
   int raiting;
};

struct AdminAccount
{
   const int id = -1; // TODO do static
   const QString login = "admin";
   const QString password = "admin";
};

enum class eSubject : int
{
    MIN = 0,
    ALL_TEXT,
    THE_SIMPLEST_GEOMETRY_OBJECTS,
    THE_SIMPLEST_GEOMETRY_OBJECTS_TITLE,
    THE_SIMPLEST_GEOMETRY_OBJECTS_DOT,
    THE_SIMPLEST_GEOMETRY_OBJECTS_LINE,
    THE_SIMPLEST_GEOMETRY_OBJECTS_BEAM,
    THE_SIMPLEST_GEOMETRY_OBJECTS_LINE_SEG,
    THE_SIMPLEST_GEOMETRY_OBJECTS_ANGLED_LINE, // 7
    SHAPES_AND_THEIR_ELEMENTS,
    BASIC_THEOREMS_OF_INITIAL_GEOMENTRY,
    MAX
};

const QString g_KeyStarts = "KeyStarts";
const QString g_firstSubjectKeyStarts = "firstSubjectKeyStarts";
const QString g_firstSubjectTitleKeyStarts = "firstSubjectTitleKeyStarts";
const QString g_firstSubjectTitleKeyEnds = "firstSubjectTitleKeyEnds";
const QString g_firstSubjectDotKeyStarts = "firstSubjectDotKeyStarts";
const QString g_firstSubjectDotKeyEnds = "firstSubjectDotKeyEnds";
const QString g_firstSubjectLineKeyStarts = "firstSubjectLineKeyStarts";
const QString g_firstSubjectLineKeyEnds = "firstSubjectLineKeyEnds";
const QString g_firstSubjectBeamKeyStarts = "firstSubjectBeamKeyStarts";
const QString g_firstSubjectBeamKeyEnds = "firstSubjectBeamKeyEnds";
const QString g_firstSubjectLineSegKeyStarts = "firstSubjectLineSegKeyStarts";
const QString g_firstSubjectLineSegKeyEnds = "firstSubjectLineSegKeyEnds";
const QString g_firstSubjectAngledLineKeyStarts = "firstSubjectAngledLineKeyStarts";
const QString g_firstSubjectAngledLineKeyEnds = "firstSubjectAngledLineKeyEnds";
const QString g_firstSubjectKeyEnds = "firstSubjectKeyEnds";
const QString g_KeyEnds = "KeyEnds";
} //namespace type
