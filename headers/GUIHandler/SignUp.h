#pragma once
#include <QDialog>
#include <QSharedPointer>
#include <QKeyEvent>

#include "FSMSignUp.h"
#include "headers/Facade.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~SignUp();

signals:
    void GUIHandlerSignUpSignal();
private slots:
    void on_signUpButton_clicked();
    void on_back_clicked();

private:
    void init();

    bool isValidData(const QString& login, const QString& password1, const QString& password2);
    bool checkLogin(const QString& login);
    bool checkName(const QString& name);
    bool checkPassword(const QString& password);

    void keyPressEvent(QKeyEvent * event);

    FSMSignUp m_FSMSignUp;

    QSharedPointer<Ui::SignUp> m_ui;
    QSharedPointer<Facade> m_Facade;


};
