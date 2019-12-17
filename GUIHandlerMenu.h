#pragma once
#include <QDialog>

#include "GUIHandlerCourseResult.h"
#include "GUIHandlerCourseMaterial.h"

class Facade;

namespace Ui {
class CourseMenu;
}

class GUIHandlerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerMenu(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~GUIHandlerMenu();

signals:
    void GUIHandlerMenuSignal();

private slots:
    void on_startCourse_clicked();

    void on_viewCourseResult_clicked();

private:
    QSharedPointer<Ui::CourseMenu> m_ui;
    QSharedPointer<GUIHandlerCourseResult> m_GUIHandlerCourseResultWindow;
    QSharedPointer<GUIHandlerCourseMaterial> m_GUIHandlerCourseMaterialWindow;
    QSharedPointer<Facade> m_Facade;
};
