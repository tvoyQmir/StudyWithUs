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

void MainWindow::on_Sign_up_btn_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_up_btn_clicked()";

    this->close();
    m_GUIHandlerSignUpWindow->show();
}

void MainWindow::on_Sign_in_btn_clicked()
{
    qDebug() << "GUIHandlerMainWindow::on_Sign_in_btn_clicked()";

    checkData(m_ui->login_lineEdit->text(), m_ui->pass_lineEdit->text());
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    const int key = event->key();
    qDebug() << "GUIHandlerMainWindow::keyPressEvent(" <<  key << ")";

    switch (key)
    {
    case Qt::Key_Return:
    {
        qDebug() << "Key_Return";
        if (m_ui->login_lineEdit->hasFocus())
        {
            // TODO add check
            m_ui->pass_lineEdit->setFocus();
        }
        else if (m_ui->pass_lineEdit->hasFocus())
        {
            m_ui->Sign_in_btn->animateClick();
        }
        else if (m_ui->Sign_up_btn->hasFocus())
        {
            m_ui->Sign_up_btn->animateClick();
        }
        else if (m_ui->Sign_in_btn->hasFocus())
        {
            m_ui->Sign_in_btn->animateClick();
        }
        else
        {
            qDebug() << "No one has focus: pressing of the Sign_in_btn";
            m_ui->Sign_up_btn->animateClick();
        }

        break;
    }
    case Qt::Key_Tab: //already implemented by QT
    {
        qDebug() << "Key_Tab";
        break;
    }
    default:
        qDebug() << "Unexpected key" << key;
        break;
    }

}

bool MainWindow::checkData(const QString& log, const QString& pass)
{
    qDebug() << "MainWindow::checkData";
    if (log.isEmpty() || pass.isEmpty())
    {
        qDebug() << "login or password is empty";

        QMessageBox msgBox;
        msgBox.setText("Please, enter valid data");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        return false;
    }

    if (m_Facade->checkData(log, pass))
    {
        qDebug() << "successfully logged";

        QMessageBox msgBox;
        msgBox.setText("You have successfully logged into your account");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        this->close();
        m_GUIHandleMenuWindow->show();

        return true;
    }
    else
    {
        qDebug() << "unsuccessfully logged";

        QMessageBox msgBox;
        msgBox.setText("You are not registered. Click on 'Sign Up' button, if you want to register");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        return false;
    }
}
