#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

#include "GUIHandlerSignUp.h"
#include "ui_SignUp.h"
#include "SignUp.h"

GUIHandlerSignUp::GUIHandlerSignUp(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::SignUp)
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
    init();
}

GUIHandlerSignUp::~GUIHandlerSignUp()
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
}

//---------------------------------------------------------------------------------------------------------------------
void GUIHandlerSignUp::on_signUpButton_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_signUpButton_clicked";

    m_FSMSignUp.submitEvent("sendData");

    const QString login = m_ui->login->text();
    const QString password1 = m_ui->pass_1->text();
    const QString password2 = m_ui->pass_2->text();

    if (isValidData(login, password1, password2))
    {
        qDebug() << "Set registration data into DB";
        m_Facade->setDataIntoAccounts(login, password1);
        m_FSMSignUp.submitEvent("finishRegistration");
    }
    else
    {
         qDebug() << "Registration data are not valid";
         m_FSMSignUp.submitEvent("reEnterData");
    }
}

void GUIHandlerSignUp::on_back_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_back_clicked";

    this->close();
    emit GUIHandlerSignUpSignal();
}

//---------------------------------------------------------------------------------------------------------------------
void GUIHandlerSignUp::init()
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

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap pix(":/src/img/minion.png");
    int width = m_ui->minion_label->width();
    int height = m_ui->minion_label->height();
    m_ui->minion_label->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
}

bool GUIHandlerSignUp::isValidData(const QString& login, const QString& password1, const QString& password2)
{
    qDebug() << "GUIHandlerSignUp::isValidData(" << login << password1 << password2 << ")";

    bool result = false;

    if (password1.isEmpty() || password2.isEmpty())
    {
        qDebug() << "Passwords are empty";
        QMessageBox::warning(this, "Sign up", "Please, enter passwords");
        result = false;
    }
    else if (password1 == password2)
    {
        if(!m_Facade->isExistInAccountsTable(login))
        {
            result = true;
        }
        else
        {
            qDebug() << "This login was registered";
            QMessageBox::warning(this, "Sign up", "This login was registered");
            result = false;
        }
    }
    else
    {
        qDebug() << "Passwords are not equal";
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
        result = false;
    }

    return result;
}
