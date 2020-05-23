#include <QDebug>
#include <QDesktopServices>

#include "headers/GUIHandler/Menu.h"
#include "ui_CourseMenu.h"
#include "headers/CustomTypes.h"

Menu::Menu(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::CourseMenu)
    , m_GUIHandlerCourseResultWindow(new CourseResult(facade))
    , m_GUIHandlerCourseMaterialWindow(new CourseMaterial(type::eSubject::THE_SIMPLEST_GEOMETRY_OBJECTS, false, facade, this))
    , m_Facade(facade)
{
     qDebug() << "GUIHandlerMenu::GUIHandlerMenu";

    m_ui->setupUi(this);

    connect(m_GUIHandlerCourseMaterialWindow.get(), &CourseMaterial::GUIHandlerCourseMaterialSignal, this, &Menu::show);
    connect(m_GUIHandlerCourseResultWindow.get(), &CourseResult::GUIHandlerCourseResultSignal, this, &Menu::show);

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Menu::~Menu()
{
    qDebug() << "GUIHandlerMenu::~GUIHandlerMenu";
}

void Menu::on_startCourse_clicked()
{
    qDebug() << "GUIHandlerMenu::on_startCourse_clicked";

    this->close();

    if (m_GUIHandlerCourseMaterialWindow)
    {
        qDebug() << "Show CourseMaterialWindow";
        m_GUIHandlerCourseMaterialWindow->show();
    }
}

void Menu::on_viewCourseResult_clicked()
{
    qDebug() << "GUIHandlerMenu::on_viewCourseResult_clicked";

    this->close();
    m_GUIHandlerCourseResultWindow->updateData();
    m_GUIHandlerCourseResultWindow->show();
}

void Menu::on_help_clicked()
{
    qDebug() << "GUIHandlerMenu::on_help_clicked";
    // TODO
}

void Menu::on_telegram_clicked()
{
    qDebug() << "GUIHandlerMenu::on_telegram_clicked";

    QString link = "https://t.me/achechui";
    QDesktopServices::openUrl(QUrl(link));
}

void Menu::on_email_clicked()
{
    qDebug() << "GUIHandlerMenu::on_email_clicked";

    QString link = "mailto:artyk16@gmail.com";
    QDesktopServices::openUrl(QUrl(link));
}
