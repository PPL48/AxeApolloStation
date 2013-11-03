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
#include <QDate>
#include <QPixmap>

FlightController::FlightController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlightController)
{
    ui->setupUi(this);

    QPixmap pixmap;
    if (!pixmap.load( ":Resources/logo.png" )) {
        qWarning("Failed to load Resources/logo.png");
    }
    ui->label_10->setPixmap(pixmap);


    //-- Set Tanggal Minimum (current Date)
    ui->deDate->setMinimumDate(QDate::currentDate());

    //-- Get Pesawat
    QList<Pesawat> pesawat = DbFactory::getPesawatModel()->getAllPesawat();
    if (pesawat.length() > 0)
        foreach (Pesawat pswt, pesawat) {
            ui->cbPesawat->addItem(pswt.toString());
        }

    //-- Get Bandara
    QList<Bandara> bandara = DbFactory::getBandaraModel()->getAllBandara();
    if (bandara.length() > 0) {
        foreach (Bandara bdr, bandara) {
            ui->cbBandaraBerangkat->addItem(bdr.toString());
            ui->cbBandaraDatang->addItem(bdr.toString());
        }
    }

    //-- Get Penerbangan
    on_btnRefresh_clicked();

    // Reset all the buffer;
}

FlightController::~FlightController()
{
    delete ui;
}

void FlightController::on_btnAviAdd_clicked()
{
    if (m_Aviator.size() < 2) {     // Pilot + Copilot
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
    DlgChooseCrew *crew = new DlgChooseCrew(this);
    connect(crew, SIGNAL(choose_crew(Pegawai)),this, SLOT(return_index(Pegawai)));

    crew->setModal(true);
    crew->show();
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
    int error = 0;
    if (m_Aviator.length() == 0 || m_Crew.length() == 0) {
        QMessageBox::critical(this,"NullNo empty value allowed", "Silahkan isi bagian yang kosong terlebih dahulu.");
        return;
    }

    //-- Building process
    PenerbanganModel *model = DbFactory::getPenerbanganModel();
    int idxFrom  = ui->cbBandaraBerangkat->currentIndex();
    int idxTo    = ui->cbBandaraDatang->currentIndex();
    int idxPlane = ui->cbPesawat->currentIndex();

    QString qval = "id_pesawat=" + QString::number(idxPlane + 1);
    QList<Penerbangan> res = model->getPenerbanganBy2(qval);
    if (!res.isEmpty()){
        //pesawat sudah pernah diassign dalam suatu penerbangan
        Penerbangan p = res.last();
        if (p.id_bandara_tujuan != (idxFrom + 1)){
            //pesawat berangkat dari bandara di mana ia tidak berada sekarang
            error = 1;
        }
        if (idxFrom == idxTo){
            //pesawat berangkat dari bandara yang sama dengan bandara tujuan
            error = 2;
        }
        if (ui->teJamBerangkat->time() == ui->teJamDatang->time()){
            //pesawat berangkat dengan waktu yang sama dengan waktu sampai di tujuan
            error = 3;
        }
        if (p.tanggal == ui->deDate->date().toString("yyyy/MM/dd")){
            //pesawat berangkat pada jam di mana ia masih ada di udara
            int arrival_hour = p.jam_tiba.left(2).toInt();
            if (ui->teJamBerangkat->time().hour() < arrival_hour){
                error = 4;
            }
        }
    } else {
        //pesawat belum pernah diassign dalam suatu penerbangan, kondisi apapun valid
    }

    model->addJam(ui->teJamBerangkat->text(), true);
    model->addJam(ui->teJamDatang->text(), false);

    model->addTanggal(ui->deDate->text());

    foreach (Pegawai pgw, m_Aviator)
        model->addAviator(pgw);

    foreach (Pegawai pgw, m_Crew)
        model->addCrew(pgw);

    model->addBandara(DbFactory::getBandaraModel()->getCache(idxFrom),true);
    model->addBandara(DbFactory::getBandaraModel()->getCache(idxTo), false);

    model->addPesawat(DbFactory::getPesawatModel()->getCache(idxPlane));

    //-- Let the model build it and get the result
    if (error == 0){
        model->createPenerbangan();

        //-- Update the list
        on_btnRefresh_clicked();

        //-- Clear the data
        ui->lvAviatorList->clear();
        ui->lvCrewList->clear();
        m_Aviator.clear();
        m_Crew.clear();

        //-- Let user know
        QMessageBox::information(this,"Success!","Penambahan jadwal sukses dilakukan");
    } else {
        QString err_message;
        if (error == 1){
            err_message = "Pesawat berangkat dari bandara di mana ia tidak berada sekarang";
        } else if (error == 2){
            err_message = "Pesawat berangkat dari bandara yang sama dengan bandara tujuan";
        } else if (error == 3){
            err_message = "Pesawat berangkat pada waktu yang sama dengan waktu sampai di tujuan";
        } else if (error == 4){
            err_message = "Pesawat berangkat pada waktu seharusnya ia masih mengudara";
        }
        QMessageBox::information(this,"Failed!","Penambahan jadwal tidak dapat dilakukan\n"+err_message);
    }
}

void FlightController::return_index(Pegawai pgw) {
    if (pgw.getJob() == "PILOT") {
        if (m_Aviator.indexOf(pgw) < 0) {
            ui->lvAviatorList->addItem(pgw.toString());
            m_Aviator.append(pgw);
        } else {
            QMessageBox::critical(this, "Data sama!", "Anda memasukkan nama yang telah terdaftar sebelumnya");
        }
    } else if (pgw.getJob() == "CABIN") {
        if (m_Crew.indexOf(pgw) < 0) {
            ui->lvCrewList->addItem(pgw.toString());
            m_Crew.append(pgw);
        } else {
            QMessageBox::critical(this, "Data sama!", "Anda memasukkan nama yang telah terdaftar sebelumnya");
        }
    }
}

void FlightController::on_btnClear_clicked()
{
    ui->lvAviatorList->clear();
    ui->lvCrewList->clear();

    m_Aviator.clear();
    m_Crew.clear();
}

void FlightController::on_btnRefresh_clicked()
{
    m_AviatorShow.clear();
    m_CrewShow.clear();
    m_Penerbangan.clear();
    ui->lvAviatorShow->clear();
    ui->lvCrewShow->clear();
    ui->lvPenerbangan->clear();

    // Get Penerbangan list
    m_Penerbangan = DbFactory::getPenerbanganModel()->getAllPenerbangan();

    // Build the Penerbangan
    if (m_Penerbangan.length() > 0) {
        foreach(Penerbangan penerbangan, m_Penerbangan) {
            ui->lvPenerbangan->addItem(penerbangan.toString());
        }
    } else {
        return;
    }

    // Get the Penerbangan and list of pegawai on it
    QMap<int, QList<int> > PnbPgwMap = DbFactory::getPenerbanganModel()->getPenerbanganPegawaiMap();

    // Get list of Aviator, mapped by their ID
    QMap<int, Pegawai> AviMap = DbFactory::getPegawaiModel()->getAviatorMappedID();

    // Get list of Crew, mapped by their ID
    QMap<int, Pegawai> CrwMap = DbFactory::getPegawaiModel()->getCrewMappedID();

    // Build the list
    QList<int> keys = PnbPgwMap.keys();
    QList<int> idxAvi = AviMap.keys();
    QList<int> idxCrw = CrwMap.keys();

    if (keys.length() > 0 && idxAvi.length() > 0 && idxCrw.length() > 0) {
        QList<Pegawai> dummy;

        foreach (int key, keys) {
            QList<int> pgwList = PnbPgwMap.value(key);

            m_AviatorShow.insert(key,dummy);
            m_CrewShow.insert(key, dummy);

            foreach(int idx, pgwList) {
                if (idxAvi.indexOf(idx)>=0) {
                    m_AviatorShow[key].append(AviMap[idx]);
                } else if (idxCrw.indexOf(idx)>=0) {
                    m_CrewShow[key].append(CrwMap[idx]);
                }
            }
        }
    }
}

void FlightController::on_lvPenerbangan_clicked(const QModelIndex &index)
{
    // Get the index of Penerbangan
    int idx = index.row();
    Penerbangan pnb = m_Penerbangan.at(idx);
    int pnbIdx = pnb.getID();

    // update the list
    ui->lvAviatorShow->clear();
    ui->lvCrewShow->clear();

    foreach(Pegawai pgw, m_AviatorShow[pnbIdx]) {
        ui->lvAviatorShow->addItem(pgw.toString());
    }
    foreach(Pegawai pgw, m_CrewShow[pnbIdx]) {
        ui->lvCrewShow->addItem(pgw.toString());
    }

    // update the labels
    ui->lbDateShow->setText(pnb.getDate());
    ui->lbDetailDepart->setText(pnb.getAirportDepart());
    ui->lbDetailArrive->setText(pnb.getAirportArrival());
    ui->lbPesawatShow->setText(pnb.getPesawat());
}

void FlightController::on_FlightManager_currentChanged(int index)
{

}
