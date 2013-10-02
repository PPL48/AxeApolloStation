#include "CheckInController.h"
#include "ui_checkincontroller.h"

#include "viewfactory.h"

CheckInController::CheckInController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckInController)
{
    ui->setupUi(this);
}

CheckInController::~CheckInController()
{
    delete ui;
}

void CheckInController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}
