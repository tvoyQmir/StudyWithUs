#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

#include "GUIHandlerSignUp.h"
#include "ui_SignUp.h"
#include "SignUp.h"

GUIHandlerSignUp::GUIHandlerSignUp(QSharedPointer<Facade> facade, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::SignUp)
    , m_GUIHandlerMenuWindow(new GUIHandlerMenu(facade))
    , m_Facade(facade)
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
    m_ui->setupUi(this);

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

GUIHandlerSignUp::~GUIHandlerSignUp()
{
    qDebug() << "GUIHandlerSignUp::GUIHandlerSignUp";
}

void GUIHandlerSignUp::on_signUpButton_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_signUpButton_clicked";

    QString login = m_ui->login->text();
    QString password;

    if (m_ui->pass_1->text() == m_ui->pass_2->text())
    {
        password = m_ui->pass_1->text();
    }
    else
    {
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
    }
    this->close();
    m_GUIHandlerMenuWindow->show();
}

void GUIHandlerSignUp::on_back_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_back_clicked";

    this->close();
    emit GUIHandlerSignUpSignal();
}
