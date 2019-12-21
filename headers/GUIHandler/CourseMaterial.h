#pragma once
#include <QDialog>
#include <QSharedPointer>

class Facade;

namespace Ui {
class CourseMaterial;
}

class CourseMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit CourseMaterial(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~CourseMaterial();

signals:
    void GUIHandlerCourseMaterialSignal();

private slots:
    void on_next_clicked();

    void on_backToCourseMenu_clicked();

private:
    QSharedPointer<Ui::CourseMaterial> m_ui;
    QSharedPointer<Facade> m_Facade;

};
