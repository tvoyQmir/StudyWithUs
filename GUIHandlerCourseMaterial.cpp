#include "GUIHandlerCourseMaterial.h"
#include "ui_CourseMaterial.h"

GUIHandlerCourseMaterial::GUIHandlerCourseMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUIHandlerCourseMaterial)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial()
{
    delete ui;
}

void GUIHandlerCourseMaterial::on_next_clicked()
{

}

void GUIHandlerCourseMaterial::on_backToCourseMenu_clicked()
{
    this->close();
    emit GUIHandlerCourseMaterialSignal();
}
