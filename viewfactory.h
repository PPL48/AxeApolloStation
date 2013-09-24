#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include "mainwindow.h"

// List the view here
#include "Views/frmlogin.h"

class ViewFactory
{
public:
    static ViewFactory* createInstance(MainWindow *a);
	static ViewFactory* instance();
    static void start();

private:
	ViewFactory();

    static MainWindow *w;
	static ViewFactory* _instance;
};

#endif // VIEWFACTORY_H
