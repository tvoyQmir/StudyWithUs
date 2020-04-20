#-------------------------------------------------
#
# Project created by QtCreator 2019-12-14T22:28:05
#
#-------------------------------------------------

QT       += core gui sql scxml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudyWithUs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    sources/fileoperations.cpp \
    sources/paintscene.cpp \
    sources/main.cpp \
    sources/MaterialContext.cpp \
    sources/CourseControler.cpp \
    sources/DBManager.cpp \
    sources/Facade.cpp \
    sources/GUIHandler/SignUp.cpp \
    sources/GUIHandler/CourseMaterial.cpp \
    sources/GUIHandler/CourseResult.cpp \
    sources/GUIHandler/MainWindow.cpp \
    sources/GUIHandler/Menu.cpp

HEADERS += \
    headers/fileoperations.h \
    headers/MaterialContext.h \
    headers/CourseControler.h \
    headers/DBManager.h \
    headers/Facade.h \
    headers/CustomTypes.h \
    headers/paintscene.h \
    headers/GUIHandler/SignUp.h \
    headers/GUIHandler/CourseMaterial.h \
    headers/GUIHandler/CourseResult.h \
    headers/GUIHandler/Menu.h \
    headers/GUIHandler/MainWindow.h

FORMS += \
    forms/MainWindow.ui \
    forms/SignUp.ui \
    forms/CourseMenu.ui \
    forms/CourseMaterial.ui \
    forms/CourseResult.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resource.qrc

STATECHARTS += \
    statecharts/FSMSignUp.scxml
