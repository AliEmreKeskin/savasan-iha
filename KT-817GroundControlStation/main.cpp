#include "mainview.h"
#include <QApplication>
#include <QtGui>
#include "mywidget.h"
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y);

    w.show();

    return a.exec();
}
