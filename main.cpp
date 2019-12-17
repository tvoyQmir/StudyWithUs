#include <QDebug>
#include <QApplication>
#include <QSharedPointer>

#include "GUIHandlerMainWindow.h"
#include "Facade.h"

int main(int argc, char *argv[])
{
    qDebug() << "main";

    QApplication a(argc, argv);

    QSharedPointer<Facade> facade(new Facade);
    facade->init();

    GUIHandlerMainWindow mainWindow(facade);
    mainWindow.show();

    return a.exec();
}
