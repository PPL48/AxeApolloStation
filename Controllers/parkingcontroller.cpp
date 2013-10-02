#include "ParkingController.h"
#include "ui_parkingcontroller.h"

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
