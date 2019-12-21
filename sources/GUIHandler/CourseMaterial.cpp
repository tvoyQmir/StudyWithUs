#include <QDebug>

#include "headers/GUIHandler/CourseMaterial.h"
#include "ui_CourseMaterial.h"

CourseMaterial::CourseMaterial(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::CourseMaterial)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerCourseMaterial::GUIHandlerCourseMaterial";

    m_ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

CourseMaterial::~CourseMaterial()
{
    qDebug() << "GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial";
}

void CourseMaterial::on_next_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_next_clicked";
}

void CourseMaterial::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseMaterialSignal();
}
