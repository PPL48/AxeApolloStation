#include "viewfactory.h"
//#include "mainwindow.h"
#include "Controllers/logincontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewFactory::createInstance();
    ViewFactory::start();

    return a.exec();
}
