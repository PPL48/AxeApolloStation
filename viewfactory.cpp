#include "viewfactory.h"

ViewFactory* ViewFactory::_instance = NULL;
MainWindow* ViewFactory::w = NULL;

ViewFactory::ViewFactory()
{
}

ViewFactory* ViewFactory::createInstance(MainWindow *a) {
    if (!_instance) {
        _instance = new ViewFactory();
        w = a;
    }
    return _instance;
}

ViewFactory* ViewFactory::instance() {
    return _instance;
}

void ViewFactory::start() {
    w->show();
}
