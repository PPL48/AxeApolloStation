#include <QApplication>

#include "viewfactory.h"
#include "dbfactory.h"

#include "Models/dbconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //-- Read the configuration

    //-- Create models
    DbConfig dbconf("127.0.0.1", "erlangga", "erlanggaIS", "erlanggadb");
    DbFactory::createInstance(dbconf);

    //-- Create views
    ViewFactory::createInstance();

    //-- Start activity
    ViewFactory::start();

    return a.exec();
}
