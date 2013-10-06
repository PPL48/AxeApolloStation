#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include <QMainWindow>

#include "Controllers/LoginController.h"
#include "Controllers/CheckInController.h"
#include "Controllers/FlightController.h"
#include "Controllers/ParkingController.h"

enum ViewType {
    vwLogin,
    vwCheckIn,
    vwParking,
    vwFlight,
};

class ViewFactory : public QWidget
{
public:

    static ViewFactory* createInstance();
	static ViewFactory* instance();
    static void start();

public slots:
    static void swapUI(ViewType view);
    static void spawnDialog(ViewType view);

private slots:
    void on_rbShowPass_toggled(bool checked);

private:
    ViewFactory();

    static QMainWindow *window;
    static ViewFactory* _instance;

    static LoginController   *m_Login;
    static CheckInController *m_CheckIn;
    static FlightController  *m_Flight;
    static ParkingController *m_Parking;
};

#endif // VIEWFACTORY_H
