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

    const QString login = m_ui->login->text();
    if (m_ui->pass_1->text() == m_ui->pass_2->text())
    {
        const QVector<type::Account> accounts = m_Facade->getAllDataFromAccounts();
        bool existInDB = false;

        foreach(const auto& account, accounts)
        {
            if (account.login == login)
            {
                existInDB = true;
            }
        }

        if(!existInDB)
        {
            qDebug() << "set registration data into DB";
            m_Facade->setDataIntoAccounts(/*login*/ m_ui->login->text(), /*password*/ m_ui->pass_1->text());

            this->close();
            m_GUIHandlerMenuWindow->show();
        }
        else
        {
            QMessageBox::warning(this, "Sign up", "This login was registered");
        }
    }
    else
    {
        QMessageBox::warning(this, "Sign up", "Passwords not equals");
    }
}

void GUIHandlerSignUp::on_back_clicked()
{
    qDebug() << "GUIHandlerSignUp::on_back_clicked";

    this->close();
    emit GUIHandlerSignUpSignal();
}
