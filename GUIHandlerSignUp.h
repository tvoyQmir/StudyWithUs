#pragma once
#include <QDialog>
#include "GUIHandlerMenu.h"

namespace Ui {
class SignUp;
}

class GUIHandlerSignUp : public QDialog
{
    Q_OBJECT

public:
    explicit GUIHandlerSignUp(QWidget *parent = nullptr);
    ~GUIHandlerSignUp();

signals:
    void GUIHandlerSignUpSignal();
private slots:
    void on_signUpButton_clicked();

    void on_back_clicked();

private:
    Ui::SignUp *ui;
    GUIHandlerMenu *GUIHandlerMenuWindow;
};
