#include <QDebug>
#include <QApplication>
#include <QSharedPointer>

#include "headers/GUIHandler/MainWindow.h"
#include "headers/Facade.h"

int main(int argc, char *argv[])
{
    qDebug() << "Starting application..";

    QApplication a(argc, argv);

    QByteArray ba("login");
    qDebug() << ba.toBase64();

    QSharedPointer<Facade> facade(new Facade);
    facade->init();

    MainWindow mainWindow(facade);
    mainWindow.show();

    return a.exec();
}
