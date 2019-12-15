#include "GUIHandlerCourseResult.h"
#include "ui_CourseResult.h"

GUIHandlerCourseResult::GUIHandlerCourseResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GUIHandlerCourseResult)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerCourseResult::~GUIHandlerCourseResult()
{
    delete ui;
}

void GUIHandlerCourseResult::on_backToCourseMenu_clicked()
{
    this->close();
    emit GUIHandlerCourseResultSignal();
}
