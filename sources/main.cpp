#include <QDebug>
#include <QApplication>
#include <QSharedPointer>

#include "headers/GUIHandler/MainWindow.h"
#include "headers/Facade.h"

int main(int argc, char *argv[])
{
    qDebug() << "main";

    QApplication a(argc, argv);

    QSharedPointer<Facade> facade(new Facade);
    facade->init();

    MainWindow mainWindow(facade);
    mainWindow.show();

    return a.exec();
}
