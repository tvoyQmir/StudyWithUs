#pragma once
#include <QDialog>

namespace Ui {
class GUIHandlerCourseMaterial;
}

class GUIHandlerCourseMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerCourseMaterial(QWidget *parent = nullptr);
    ~GUIHandlerCourseMaterial();

signals:
    void GUIHandlerCourseMaterialSignal();

private slots:
    void on_next_clicked();

    void on_backToCourseMenu_clicked();

private:
    Ui::GUIHandlerCourseMaterial *ui;
};
