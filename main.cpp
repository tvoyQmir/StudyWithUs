#include "GUIHandlerMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIHandlerMainWindow w;
    w.show();

    return a.exec();
}
