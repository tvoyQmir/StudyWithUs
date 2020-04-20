#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

#include "headers/GUIHandler/SignUp.h"
#include "ui_SignUp.h"

SignUp::SignUp(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::SignUp)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
    init();
}

SignUp::~SignUp()
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
}

//---------------------------------------------------------------------------------------------------------------------
void SignUp::on_signUpButton_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_signUpButton_clicked";

    m_FSMSignUp.submitEvent("sendData");

    const QString login = m_ui->login->text();
    const QString password1 = m_ui->pass_1->text();
    const QString password2 = m_ui->pass_2->text();

    if (isValidData(login, password1, password2))
    {
        qDebug() << "Set registration data into DB";
        m_Facade->setDataIntoAccounts(QString(login.toStdString().c_str()), QString(password2.toStdString().c_str()), "default");
        m_FSMSignUp.submitEvent("finishRegistration");
    }
    else
    {
         qDebug() << "Registration data are not valid";
         m_FSMSignUp.submitEvent("reEnterData");
    }
}

void SignUp::on_back_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_back_clicked";

    this->close();
    emit GUIHandlerSignUpSignal();
}

//---------------------------------------------------------------------------------------------------------------------
void SignUp::init()
{
    m_ui->setupUi(this);
    m_FSMSignUp.init();
    m_FSMSignUp.start();

    //TODO implement FSM

    m_FSMSignUp.connectToState("waitingForEnterData", QScxmlStateMachine::onEntry([&]()
    {
        qDebug() << "onEntry waitingForEnterData: Staring session of registration";
        //TODO
    }));

    m_FSMSignUp.connectToState("waitingForCheckData", QScxmlStateMachine::onEntry([&]()
    {
        qDebug() << "onEntry waitingForCheckData";
        //TODO
    }));

    m_FSMSignUp.connectToState("Final_1", QScxmlStateMachine::onEntry([&]()
    {
        qDebug() << "onEntry Final_1";
        this->close();
        emit GUIHandlerSignUpSignal();
    }));

    QPixmap bkgnd(":/bkgnd/img/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap pix(":/src/img/minion.png");
    int width = m_ui->minion_label->width();
    int height = m_ui->minion_label->height();
    m_ui->minion_label->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
}

bool SignUp::isValidData(const QString& login, const QString& password1, const QString& password2)
{
    qDebug() << "GUIHandlerSignUp::isValidData(" << login << password1 << password2 << ")";

    bool result = false;

    if (!checkLogin(login) || !checkName("name") || !checkPassword(password1) || !checkPassword(password2))
    {
        qDebug() << "Data failed check";
        return false;
    }


    if (password1 == password2)
    {
        if(!m_Facade->isExistInAccountsTable(login))
        {            
            qDebug() << "You are succesfuly registered";
            result = true;

            QMessageBox msgBox;
            msgBox.setText("You are succesfuly registered");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.button(QMessageBox::Ok)->animateClick(3000);
            msgBox.exec();
        }
        else
        {
            qDebug() << "This login was registered";
            result = false;

            QMessageBox msgBox;
            msgBox.setText("This login was registered");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.button(QMessageBox::Ok)->animateClick(3000);
            msgBox.exec();
        }
    }
    else
    {
        qDebug() << "Passwords are not equal";
        result = false;

        QMessageBox msgBox;
        msgBox.setText("Passwords are not equal");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();
    }

    return result;
}

bool SignUp::checkLogin(const QString& login)
{
    qDebug() << "checkLogin" << login;

    QVector <QString> rules{" "};

    if (login.isEmpty())
    {
        qDebug() << "Login is empty";

        QMessageBox msgBox;
        msgBox.setText("Login is empty. Please, enter this one.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        return false;
    }

    for (int i = 0; i < rules.size(); ++i)
    {
        if (login.indexOf(rules[i]) != -1)
        {
            qDebug() << "login has :" << rules[i];

            QString str = "Please, enter valid data. Login has wrong symbol: ";
            str.append(rules[i]);

            QMessageBox msgBox;
            msgBox.setText(str);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.button(QMessageBox::Ok)->animateClick(3000);
            msgBox.exec();

            return false;
        }
    }

    return true;
}

bool SignUp::checkName(const QString& name)
{
    qDebug() << "checkName" << name;

    QVector <QString> rules{" ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "~", "`", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "+", "=", "\\", "|", "{", "[", "}", "]", ":", ";", "\"", "<", ",", ".", ">", "?", "/"};

    if (name.isEmpty())
    {
        qDebug() << "Name is empty";

        QMessageBox msgBox;
        msgBox.setText("Name is empty. Please, enter this one.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        return false;

    }

    for (int i = 0; i < rules.size(); ++i)
    {
        if (name.indexOf(rules[i]) != -1)
        {
            qDebug() << "Name has :" << rules[i];
            QString str = "Please, enter valid data. Name has wrong symbol: ";
            str.append(rules[i]);

            QMessageBox msgBox;
            msgBox.setText(str);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.button(QMessageBox::Ok)->animateClick(3000);
            msgBox.exec();

            return false;
        }
    }

    return true;
}

bool SignUp::checkPassword(const QString& password)
{
    qDebug() << "checkPassword" << password;

    QVector <QString> rules{" "};

    if (password.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Password is empty. Please, enter this one.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.button(QMessageBox::Ok)->animateClick(3000);
        msgBox.exec();

        return false;
    }

    for (int i = 0; i < rules.size(); ++i)
    {
        if (password.indexOf(rules[i]) != -1)
        {
            qDebug() << "login has :" << rules[i];
            QString str = "Please, enter valid data. Password has wrong symbol: ";
            str.append(rules[i]);

            QMessageBox msgBox;
            msgBox.setText(str);
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.button(QMessageBox::Ok)->animateClick(3000);
            msgBox.exec();

            return false;
        }
    }

    return true;
}

void SignUp::keyPressEvent(QKeyEvent * event)
{
    const int key = event->key();
    qDebug() << "GUIHandlerMainWindow::keyPressEvent(" <<  key << ")";

    switch (key)
    {
    case Qt::Key_Return:
    {
        qDebug() << "Key_Return";
        if (m_ui->name->hasFocus())
        {
            if (checkName(m_ui->name->text()))
            {
                m_ui->login->setFocus();
            }
            else
            {
                qDebug() << "Data failed check";
            }
        }
        else if (m_ui->login->hasFocus())
        {
            if (checkLogin(m_ui->login->text()))
            {
                m_ui->pass_1->setFocus();
            }
            else
            {
                qDebug() << "Data failed check";
            }
        }
        else if (m_ui->pass_1->hasFocus())
        {
            if (checkPassword(m_ui->pass_1->text()))
            {
                m_ui->pass_2->setFocus();
            }
            else
            {
                qDebug() << "Data failed check";
            }
        }
        else if (m_ui->pass_2->hasFocus())
        {
            if (checkPassword(m_ui->pass_2->text()))
            {
                m_ui->signUpButton->animateClick();
            }
            else
            {
                qDebug() << "Data failed check";
            }
        }
        else if (m_ui->back->hasFocus())
        {
            m_ui->back->animateClick();
        }
        else
        {
            qDebug() << "No one has focus: pressing of the Sign_in_btn";
            m_ui->signUpButton->animateClick();
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
