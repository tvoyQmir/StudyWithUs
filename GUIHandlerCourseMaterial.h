#pragma once
#include <QDialog>
#include <QSharedPointer>

class Facade;

namespace Ui {
class GUIHandlerCourseMaterial;
}

class GUIHandlerCourseMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerCourseMaterial(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~GUIHandlerCourseMaterial();

signals:
    void GUIHandlerCourseMaterialSignal();

private slots:
    void on_next_clicked();

    void on_backToCourseMenu_clicked();

private:
    QSharedPointer<Ui::GUIHandlerCourseMaterial> m_ui;
    QSharedPointer<Facade> m_Facade;

};
