#pragma once
#include <QMainWindow>
#include "GUIHandlerSignUp.h"
#include "GUIHandlerMenu.h"

namespace Ui {
class MainWindow;
}

class GUIHandlerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUIHandlerMainWindow(QWidget *parent = nullptr);
    ~GUIHandlerMainWindow();

private slots:
    void on_Sign_up_clicked();

    void on_Sign_in_clicked();

private:
    Ui::MainWindow *ui;
    GUIHandlerSignUp *GUIHandlerSignUpWindow;
    GUIHandlerMenu *GUIHandleMenuWindow;
};
