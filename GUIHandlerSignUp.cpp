#include "GUIHandlerSignUp.h"
#include "ui_SignUp.h"
#include <QMessageBox>
#include <QPixmap>
#include "SignUp.h"

GUIHandlerSignUp::GUIHandlerSignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp),
    GUIHandlerMenuWindow(new GUIHandlerMenu())
{
    ui->setupUi(this);

    QPixmap bkgnd(":/bkgnd/background/mainBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPixmap pix(":/src/img/minion.png");
    int w = ui->minion_label->width();
    int h = ui->minion_label->height();
    ui->minion_label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

GUIHandlerSignUp::~GUIHandlerSignUp()
{
    delete ui;
}

void GUIHandlerSignUp::on_signUpButton_clicked()
{
    QString login = ui->login->text();
    QString password;

    if (ui->pass_1->text() == ui->pass_2->text())
    {
        password = ui->pass_1->text();
    }
    else
    {
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
    }
    this->close();
    GUIHandlerMenuWindow->show();
}

void GUIHandlerSignUp::on_back_clicked()
{
    this->close();
    emit GUIHandlerSignUpSignal();
}
