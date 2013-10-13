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

#include <QMessageBox>

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

    //-- Get Bandara
    QList<Bandara> bandara = DbFactory::getBandaraModel()->getAllBandara();

    foreach (Bandara bdr, bandara) {
        ui->cbBandaraBerangkat->addItem(bdr.toString());
        ui->cbBandaraDatang->addItem(bdr.toString());
    }

    //-- Get Penerbangan

    // Reset all the buffer;
}

FlightController::~FlightController()
{
    delete ui;
}

void FlightController::on_btnAviAdd_clicked()
{
    if (m_Aviator.size() < 2) {
        DlgChooseAviator *avi = new DlgChooseAviator(this);
        connect(avi, SIGNAL(choose_aviator(Pegawai)), this, SLOT(return_index(Pegawai)));

        avi->setModal(true);
        avi->show();
    } else {
        QMessageBox::critical(this,"Illegal Policy", "Hanya dua pilot yang diperbolehkan.");
    }
}

void FlightController::on_btnCrewAdd_clicked()
{
    if (m_Crew.size() < 2) {
        DlgChooseCrew *crew = new DlgChooseCrew(this);
        connect(crew, SIGNAL(choose_crew(Pegawai)),this, SLOT(return_index(Pegawai)));

        crew->setModal(true);
        crew->show();
    } else {
        QMessageBox::critical(this,"Illegal Policy", "Hanya dua awak kabin yang diperbolehkan.");
    }
}


void FlightController::on_btnAviRemove_clicked()
{
    int index = ui->lvAviatorList->currentIndex().row();
    if (index >= 0) {
        ui->lvAviatorList->takeItem(index);
        m_Aviator.removeAt(index);
    }
}

void FlightController::on_btnCrewRemove_clicked()
{
    int index = ui->lvCrewList->currentIndex().row();
    if (index >= 0) {
        ui->lvCrewList->takeItem(index);
        m_Crew.removeAt(index);
    }
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
    if (pgw.getJob() == "PILOT") {
        ui->lvAviatorList->addItem(pgw.toString());
        m_Aviator.append(pgw);

    } else if (pgw.getJob() == "CABIN") {
        ui->lvCrewList->addItem(pgw.toString());
        m_Crew.append(pgw);
    }
}


void FlightController::on_btnClear_clicked()
{
    ui->lvAviatorList->clear();
    ui->lvCrewList->clear();

    m_Aviator.clear();
    m_Crew.clear();
}
