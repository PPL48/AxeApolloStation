#include "viewfactory.h"

ViewFactory* ViewFactory::_instance = NULL;
QMainWindow* ViewFactory::window = NULL;

LoginController*   ViewFactory::m_Login   = NULL;
CheckInController* ViewFactory::m_CheckIn = NULL;
ParkingController* ViewFactory::m_Parking = NULL;
FlightController*  ViewFactory::m_Flight  = NULL;


ViewFactory::ViewFactory()
{
}

ViewFactory* ViewFactory::createInstance() {
    if (!_instance) {
        _instance   = new ViewFactory;
        m_Login     = new LoginController(_instance);
        m_CheckIn   = new CheckInController(_instance);
        m_Parking   = new ParkingController(_instance);
        m_Flight    = new FlightController(_instance);

        window      = m_Login;
    }
    return _instance;
}

ViewFactory* ViewFactory::instance() {
    return _instance;
}

void ViewFactory::start() {
    window->show();
}

void ViewFactory::swapUI(ViewType view) {
    m_Login->hide();
    m_CheckIn->hide();
    m_Parking->hide();
    m_Flight->hide();

    switch (view) {
    case vwLogin:
        m_Login->show();
        window = m_Login;
        break;
    case vwCheckIn:
        m_CheckIn->show();
        window = m_CheckIn;
        break;
    case vwParking:
        m_Parking->show();
        window = m_Parking;
        break;
    case vwFlight:
        m_Flight->show();
        window = m_Flight;
        break;
    }
}
