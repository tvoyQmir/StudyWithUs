#pragma once
#include <QDialog>

#include "CourseResult.h"
#include "CourseMaterial.h"

class Facade;

namespace Ui {
class CourseMenu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~Menu();

signals:
    void GUIHandlerMenuSignal();

private slots:
    void on_startCourse_clicked();
    void on_viewCourseResult_clicked();
    void on_help_clicked();
    void on_telegram_clicked();
    void on_email_clicked();

private:
    QSharedPointer<Ui::CourseMenu> m_ui;
    QSharedPointer<CourseResult> m_GUIHandlerCourseResultWindow;
    QSharedPointer<CourseMaterial> m_GUIHandlerCourseMaterialWindow;
    QSharedPointer<Facade> m_Facade;
};
