#include "GUIHandlerMenu.h"
#include "ui_CourseMenu.h"

GUIHandlerMenu::GUIHandlerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseMenu),
    GUIHandlerCourseResultWindow(new GUIHandlerCourseResult()),
    GUIHandlerCourseMaterialWindow(new GUIHandlerCourseMaterial())
{
    ui->setupUi(this);

    connect(GUIHandlerCourseMaterialWindow, &GUIHandlerCourseMaterial::GUIHandlerCourseMaterialSignal, this, &GUIHandlerMenu::show);
    connect(GUIHandlerCourseResultWindow, &GUIHandlerCourseResult::GUIHandlerCourseResultSignal, this, &GUIHandlerMenu::show);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerMenu::~GUIHandlerMenu()
{
    delete ui;
}

void GUIHandlerMenu::on_startCourse_clicked()
{
    this->close();
    GUIHandlerCourseMaterialWindow->show();
}

void GUIHandlerMenu::on_viewCourseResult_clicked()
{
    this->close();
    GUIHandlerCourseResultWindow->show();
}
