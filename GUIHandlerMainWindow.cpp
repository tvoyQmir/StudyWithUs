#include <QMessageBox>
#include <QDebug>

#include "GUIHandlerMainWindow.h"
#include "ui_MainWindow.h"

GUIHandlerMainWindow::GUIHandlerMainWindow(QSharedPointer<Facade> facade, QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_GUIHandlerSignUpWindow(new GUIHandlerSignUp(facade))
    , m_GUIHandleMenuWindow(new GUIHandlerMenu(facade))
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerMainWindow::GUIHandlerMainWindow";

     m_ui->setupUi(this);

    connect(m_GUIHandleMenuWindow.get(), &GUIHandlerMenu::GUIHandlerMenuSignal, this, &GUIHandlerMainWindow::show);
    connect(m_GUIHandlerSignUpWindow.get(), &GUIHandlerSignUp::GUIHandlerSignUpSignal, this, &GUIHandlerMainWindow::show);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerMainWindow::~GUIHandlerMainWindow()
{
    qDebug() << "GUIHandlerMainWindow::~GUIHandlerMainWindow";
}

void GUIHandlerMainWindow::on_Sign_up_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_up_clicked";

    this->close();
    m_GUIHandlerSignUpWindow->show();
}

void GUIHandlerMainWindow::on_Sign_in_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_in_clicked";

    QString login = m_ui->login->text();
    QString password;
    const bool result = true; /*dbMng.find(ui->pass->text())*/

    if (result)
    {
        password = m_ui->pass->text();
    }
    else
    {
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
    }

    this->close();
    m_GUIHandleMenuWindow->show();
}
