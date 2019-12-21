#pragma once
#include <QDialog>
#include <QSharedPointer>

#include "SignUp.h"
#include "Facade.h"

namespace Ui {
class SignUp;
}

class GUIHandlerSignUp : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerSignUp(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~GUIHandlerSignUp();

signals:
    void GUIHandlerSignUpSignal();
private slots:
    void on_signUpButton_clicked();

    void on_back_clicked();

private:
    void init();
    bool isValidData(const QString& login, const QString& password1, const QString& password2);

    SignUp m_FSMSignUp;

    QSharedPointer<Ui::SignUp> m_ui;
    QSharedPointer<Facade> m_Facade;


};
