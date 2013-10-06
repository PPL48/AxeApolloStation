#include "FlightController.h"
#include "ui_flightcontroller.h"

#include "viewfactory.h"
#include "dbfactory.h"

#include "Models/bandaramodel.h"
#include "Models/pegawaimodel.h"
#include "Models/penerbanganmodel.h"
#include "Models/pesawatmodel.h"

#include "Views/dlgchooseaviator.h"
#include "Views/dlgchoosecrew.h"

#include <QListWidgetItem>

FlightController::FlightController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlightController)
{
    ui->setupUi(this);

    //-- Get Pesawat
    QList<Pesawat> pesawat = DbFactory::getPesawatModel()->getAllPesawat();

    foreach (Pesawat pswt, pesawat) {
        ui->cbPesawat->addItem(pswt.toString());
    }

    //QList<Bandara> bandara = DbFactory::getBandaraModel()->getAllBandara();
}

FlightController::~FlightController()
{
    delete ui;
}

void FlightController::on_btnAviAdd_clicked()
{
    DlgChooseAviator *avi = new DlgChooseAviator(this);
    connect(avi, SIGNAL(choose_aviator(Pegawai)), this, SLOT(on_return_index(Pegawai)));

    avi->show();
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

void FlightController::on_btnCreate_clicked()
{

}

void FlightController::on_return_index(Pegawai pgw) {
    ui->lvAviatorList->addItem(pgw.toString());
}
