#pragma once
#include <QMainWindow>
#include <QSharedPointer>

#include "GUIHandlerSignUp.h"
#include "GUIHandlerMenu.h"

class Facade;

namespace Ui {
class MainWindow;
}

class GUIHandlerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUIHandlerMainWindow(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~GUIHandlerMainWindow();

private slots:
    void on_Sign_up_clicked();

    void on_Sign_in_clicked();

private:
    QSharedPointer<Ui::MainWindow> m_ui;
    QSharedPointer<GUIHandlerSignUp> m_GUIHandlerSignUpWindow;
    QSharedPointer<GUIHandlerMenu> m_GUIHandleMenuWindow;
    QSharedPointer<Facade> m_Facade;
};
