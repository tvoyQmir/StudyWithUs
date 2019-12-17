#pragma once
#include <QDialog>
#include <QSharedPointer>

class Facade;

namespace Ui {
class GUIHandlerCourseResult;
}

class GUIHandlerCourseResult : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerCourseResult(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~GUIHandlerCourseResult();

signals:
    void GUIHandlerCourseResultSignal();

private slots:
    void on_backToCourseMenu_clicked();

private:
    QSharedPointer<Ui::GUIHandlerCourseResult> m_ui;
    QSharedPointer<Facade> m_Facade;
};
