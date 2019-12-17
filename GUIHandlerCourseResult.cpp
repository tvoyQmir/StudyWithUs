#include <QDebug>

#include "GUIHandlerCourseResult.h"
#include "ui_CourseResult.h"

GUIHandlerCourseResult::GUIHandlerCourseResult(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::GUIHandlerCourseResult)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerCourseResult::GUIHandlerCourseResult";
    m_ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerCourseResult::~GUIHandlerCourseResult()
{
    qDebug() << "GUIHandlerCourseResult::~GUIHandlerCourseResult";
}

void GUIHandlerCourseResult::on_backToCourseMenu_clicked()
{
    qDebug() << "GUIHandlerCourseResult::on_backToCourseMenu_clicked";

    this->close();
    emit GUIHandlerCourseResultSignal();
}
