#include "viewfactory.h"

ViewFactory* ViewFactory::_instance = NULL;
MainWindow* ViewFactory::window = NULL;

ViewFactory::ViewFactory()
{
}

ViewFactory* ViewFactory::createInstance(MainWindow *w) {
    if (!_instance) {
        _instance = new ViewFactory();
        window = w;
    }
    return _instance;
}

ViewFactory* ViewFactory::instance() {
    return _instance;
}

void ViewFactory::start() {
    window->show();
}

void ViewFactory::changeUI(ViewType view) {
    switch (view) {
    case vwLogin:
        break;
    case vwCheckIn1:
        break;
    case vwCheckIn2:
        break;
    case vwChooseAviator:
        break;
    case vwChooseCrew:
        break;
    case vwManageFlight:
        break;
    }
}
