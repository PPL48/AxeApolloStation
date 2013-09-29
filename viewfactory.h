#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include "mainwindow.h"

enum ViewType {
    vwLogin,
    vwCheckIn1,
    vwCheckIn2,
    vwChooseAviator,
    vwChooseCrew,
    vwManageFlight
};

class ViewFactory
{
public:

    static ViewFactory* createInstance(MainWindow *mainWindow);
	static ViewFactory* instance();
    static void start();

    static void changeUI(ViewType view);

private:
	ViewFactory();

    static MainWindow *window;
    static ViewFactory* _instance;
};

#endif // VIEWFACTORY_H
