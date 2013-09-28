#include "viewfactory.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow w;

    ViewFactory::createInstance(&w);
    ViewFactory::start();

    return a.exec();
}
