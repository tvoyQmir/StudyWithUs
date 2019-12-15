#pragma once
#include <QDialog>

namespace Ui {
class GUIHandlerCourseResult;
}

class GUIHandlerCourseResult : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerCourseResult(QWidget *parent = nullptr);
    ~GUIHandlerCourseResult();

signals:
    void GUIHandlerCourseResultSignal();

private slots:
    void on_backToCourseMenu_clicked();

private:
    Ui::GUIHandlerCourseResult *ui;
};
