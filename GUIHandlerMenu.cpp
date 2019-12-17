#include <QDebug>

#include "GUIHandlerMenu.h"
#include "ui_CourseMenu.h"

GUIHandlerMenu::GUIHandlerMenu(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::CourseMenu)
    , m_GUIHandlerCourseResultWindow(new GUIHandlerCourseResult(facade))
    , m_GUIHandlerCourseMaterialWindow(new GUIHandlerCourseMaterial(facade))
    , m_Facade(facade)
{
     qDebug() << "GUIHandlerMenu::GUIHandlerMenu";

    m_ui->setupUi(this);

    connect(m_GUIHandlerCourseMaterialWindow.get(), &GUIHandlerCourseMaterial::GUIHandlerCourseMaterialSignal, this, &GUIHandlerMenu::show);
    connect(m_GUIHandlerCourseResultWindow.get(), &GUIHandlerCourseResult::GUIHandlerCourseResultSignal, this, &GUIHandlerMenu::show);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerMenu::~GUIHandlerMenu()
{
    qDebug() << "GUIHandlerMenu::~GUIHandlerMenu";
}

void GUIHandlerMenu::on_startCourse_clicked()
{
    qDebug() << "GUIHandlerMenu::on_startCourse_clicked";

    this->close();
    m_GUIHandlerCourseMaterialWindow->show();
}

void GUIHandlerMenu::on_viewCourseResult_clicked()
{
    qDebug() << "GUIHandlerMenu::on_viewCourseResult_clicked";

    this->close();
    m_GUIHandlerCourseResultWindow->show();
}
