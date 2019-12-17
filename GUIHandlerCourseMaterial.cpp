#include <QDebug>

#include "GUIHandlerCourseMaterial.h"
#include "ui_CourseMaterial.h"

GUIHandlerCourseMaterial::GUIHandlerCourseMaterial(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::GUIHandlerCourseMaterial)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerCourseMaterial::GUIHandlerCourseMaterial";

    m_ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial()
{
    qDebug() << "GUIHandlerCourseMaterial::~GUIHandlerCourseMaterial";
}

void GUIHandlerCourseMaterial::on_next_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_next_clicked";
}

void GUIHandlerCourseMaterial::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseMaterial::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseMaterialSignal();
}
