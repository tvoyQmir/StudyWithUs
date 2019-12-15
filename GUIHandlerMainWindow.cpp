#include "GUIHandlerMainWindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>

GUIHandlerMainWindow::GUIHandlerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GUIHandleMenuWindow = new GUIHandlerMenu();
    GUIHandlerSignUpWindow = new GUIHandlerSignUp();

    connect(GUIHandleMenuWindow, &GUIHandlerMenu::GUIHandlerMenuSignal, this, &GUIHandlerMainWindow::show);
    connect(GUIHandlerSignUpWindow, &GUIHandlerSignUp::GUIHandlerSignUpSignal, this, &GUIHandlerMainWindow::show);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

GUIHandlerMainWindow::~GUIHandlerMainWindow()
{
    delete ui;
}

void GUIHandlerMainWindow::on_Sign_up_clicked()
{
    this->close();
    GUIHandlerSignUpWindow->show();
}

void GUIHandlerMainWindow::on_Sign_in_clicked()
{
    QString login = ui->login->text();
    QString password;
    const bool result = true; /*dbMng.find(ui->pass->text())*/

    if (result)
    {
        password = ui->pass->text();
    }
    else
    {
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
    }

    this->close();
    GUIHandleMenuWindow->show();
}
