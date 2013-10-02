#include "FlightController.h"
#include "ui_flightcontroller.h"

#include "viewfactory.h"

FlightController::FlightController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlightController)
{
    ui->setupUi(this);
}

FlightController::~FlightController()
{
    delete ui;
}

void FlightController::on_btnAviAdd_clicked()
{

}

void FlightController::on_btnAviRemove_clicked()
{

}

void FlightController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}
