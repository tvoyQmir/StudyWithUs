#include <QMessageBox>
#include <QDebug>

#include "headers/GUIHandler/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QSharedPointer<Facade> facade, QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_GUIHandlerSignUpWindow(new SignUp(facade))
    , m_GUIHandleMenuWindow(new Menu(facade))
    , m_Facade(facade)
    , m_activeAccount("")
{
    qDebug() << "GUIHandlerMainWindow::GUIHandlerMainWindow";

     m_ui->setupUi(this);

    connect(m_GUIHandleMenuWindow.get(), &Menu::GUIHandlerMenuSignal, this, &MainWindow::show);
    connect(m_GUIHandlerSignUpWindow.get(), &SignUp::GUIHandlerSignUpSignal, this, &MainWindow::show);

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    qDebug() << "GUIHandlerMainWindow::~GUIHandlerMainWindow";
}

void MainWindow::on_Sign_up_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_up_clicked";

    this->close();
    m_GUIHandlerSignUpWindow->show();
}

void MainWindow::on_Sign_in_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_in_clicked";

    const QString login = m_ui->login->text();
    const QString password = m_ui->pass->text();

    if (login.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Sign in", "Please, enter valid data");
        return;
    }

    const bool result = m_Facade->checkData(login, password);

    if (result)
    {
        qDebug() << "successfully logged";
        QMessageBox::information(this, "Sign in", "You have successfully logged into your account"); //TODO add timeot on all messageBox

        this->close(); // TODO do without closing window
        m_GUIHandleMenuWindow->show();
    }
    else
    {
        QMessageBox::warning(this, "Sign in", "You are not registered. Click on 'Sign Up' button, if you want to register");
    }
}
