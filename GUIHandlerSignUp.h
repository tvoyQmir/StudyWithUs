#pragma once
#include <QDialog>
#include <QSharedPointer>

#include "GUIHandlerMenu.h"
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
    QSharedPointer<Ui::SignUp> m_ui;
    QSharedPointer<GUIHandlerMenu> m_GUIHandlerMenuWindow;
    QSharedPointer<Facade> m_Facade;
};
