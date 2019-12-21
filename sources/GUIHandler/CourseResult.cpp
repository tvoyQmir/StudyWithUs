#include <QDebug>

#include "headers/GUIHandler/CourseResult.h"
#include "ui_CourseResult.h"

CourseResult::CourseResult(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::CourseResult)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerCourseResult::GUIHandlerCourseResult";
    m_ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

CourseResult::~CourseResult()
{
    qDebug() << "GUIHandlerCourseResult::~GUIHandlerCourseResult";
}

void CourseResult::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseResult::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseResultSignal();
}
