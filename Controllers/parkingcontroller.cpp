#include "ParkingController.h"
#include "ui_parkingcontroller.h"

#include "viewfactory.h"

ParkingController::ParkingController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParkingController)
{
    ui->setupUi(this);
}

ParkingController::~ParkingController()
{
    delete ui;
}

void ParkingController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}
