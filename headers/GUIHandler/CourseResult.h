#pragma once
#include <QDialog>
#include <QSharedPointer>

class Facade;

namespace Ui {
class CourseResult;
}

class CourseResult : public QDialog
{
    Q_OBJECT

public:
    explicit CourseResult(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~CourseResult();

signals:
    void GUIHandlerCourseResultSignal();

private slots:
    void on_backToCourseMenu_clicked();

private:
    QSharedPointer<Ui::CourseResult> m_ui;
    QSharedPointer<Facade> m_Facade;
};
