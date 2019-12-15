#pragma once
#include <QDialog>
#include "GUIHandlerCourseResult.h"
#include "GUIHandlerCourseMaterial.h"

namespace Ui {
class CourseMenu;
}

class GUIHandlerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerMenu(QWidget *parent = nullptr);
    ~GUIHandlerMenu();

signals:
    void GUIHandlerMenuSignal();

private slots:
    void on_startCourse_clicked();

    void on_viewCourseResult_clicked();

private:
    Ui::CourseMenu *ui;
    GUIHandlerCourseResult *GUIHandlerCourseResultWindow;
    GUIHandlerCourseMaterial *GUIHandlerCourseMaterialWindow;
};
