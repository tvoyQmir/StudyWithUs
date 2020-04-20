#pragma once
#include <QMainWindow>
#include <QSharedPointer>
#include <QKeyEvent>

#include "SignUp.h"
#include "Menu.h"

class Facade;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSharedPointer<Facade> facade, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sign_up_btn_clicked();
    void on_Sign_in_btn_clicked();

private:
    void keyPressEvent(QKeyEvent * event) override;
    bool checkData(const QString& log, const QString& pass);

    QSharedPointer<Ui::MainWindow> m_ui;
    QSharedPointer<SignUp> m_GUIHandlerSignUpWindow;
    QSharedPointer<Menu> m_GUIHandleMenuWindow;
    QSharedPointer<Facade> m_Facade;

    QString m_activeAccount;
};
