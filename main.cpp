#include "viewfactory.h"
//#include "mainwindow.h"
#include "Controllers/logincontroller.h"
#include <QApplication>

#include "Models/dbconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbConfig db;

    ViewFactory::createInstance();
    ViewFactory::start();

    return a.exec();
}
