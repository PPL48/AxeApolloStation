#include "CheckInController.h"
#include "ui_checkincontroller.h"

#include "viewfactory.h"
#include "dbfactory.h"
#include <QMessageBox>
#include "Models/pemesanmodel.h"

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

// FUNGSI2 TAMBAHAN

QString CheckInController::getAirportCode(qint32 id){
    // Getting airport code
    QString result = "";
    QString tempid = QString::number(id);
    QList<Bandara> bandara = DbFactory::getBandaraModel()->getBandaraBy("bandara.id="+tempid);
    if (bandara.length() != 0){
        Bandara b = bandara.at(0);
        result = b.kode;
    }
    return result;
}

// FUNGSI2 SLOT

void CheckInController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear (set default)
    ui->lbNama->setText("<Name>");

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}

void CheckInController::on_btnSearch_clicked(){
    QString resNum = ui->resNum->text();
    QString idCardNum = ui->idCardNum->text();

    QList<Pemesan> pemesan = DbFactory::getPemesanModel()->getPemesanBy("pemesan.id_pemesanan=pemesanan.id AND pemesan.id="+idCardNum+" AND pemesanan.kode_booking="+resNum);

    if(pemesan.length()!=1){
        QMessageBox::warning(this,tr("Search Failed"),tr("Reservation number / ID Card Number not found"),QMessageBox::Ok);
    }else{
        Pemesan p = pemesan.at(0);
        ui->lbApplicant->setText(p.nama+" ("+resNum+")");
        QString idpemesanan = QString::number(p.id_pemesanan);

        QList<Penumpang> penumpang = DbFactory::getPenumpangModel()->getPenumpangBy("id_pemesanan="+idCardNum);
        QList<Penerbangan> penerbangan = DbFactory::getPenerbanganModel()->getPenerbanganBy2("pemesanan.id_penerbangan=penerbangan.id AND pemesanan.id="+idpemesanan);

        qDebug() << penerbangan.length() << endl;
        qDebug() << penumpang.length() << endl;

        if(penumpang.length()!=0 && penerbangan.length()!= 0){

            ui->listPassenger->clear();
            for(int i=0; i<penumpang.length(); i++){
                ui->listPassenger->addItem("["+idpemesanan+"]"+penumpang.at(i).nama);
            }
            ui->listPassenger->setCurrentRow(0);

            Penumpang pen =  penumpang.at(0);
            Penerbangan flight = penerbangan.at(0);
            ui->lbNama->setText(pen.titel+" "+pen.nama);
            ui->lbFlightNumber->setText(QString::number(flight.id));
            ui->lbSchedule->setText(getAirportCode(flight.id_bandara_asal)+" -> "+getAirportCode(flight.id_bandara_tujuan));
            ui->lbBoardingTime->setText(flight.jam_berangkat);
            ui->lbGate->setText("A");

            QString tempseat = DbFactory::getPenumpangModel()->getSeatNumberBy("pemesanan.id=penumpang.id_pemesanan AND pemesanan.id="+idpemesanan);
            ui->lbSeat->setText(tempseat);
        }
    }
}

void CheckInController::on_cbAddLuggage_stateChanged(int arg1)
{
    if (arg1){

    } else {

    }
}

void CheckInController::on_cbAddLuggage_toggled(bool checked)
{
    if(checked) {
        //ui->frmRight->setVisible(false);
    } else {

    }
}

void CheckInController::on_btnAddLuggage_clicked()
{
    QString inputWeight = ui->sbAddLuggage->text();
    QString currentWeight= ui->lbChargeWeight->text();
    double tempInput;
    double tempWeight;
    double tempCharge;
    QString finalWeight;
    QString finalCharge;

    ui->sbAddLuggage->setValue(0.00d);

    currentWeight = currentWeight.left(currentWeight.length()-3);

    ui->listWeight->addItem("KodeBagasi ["+inputWeight+" Kg]");

    tempInput = inputWeight.toDouble();
    tempWeight = currentWeight.toDouble();

    tempWeight = tempWeight + tempInput;
    tempCharge = (tempWeight - 20.00)*20000;

    if (tempCharge < 0){tempCharge = 0;}

    finalWeight = QString::number(tempWeight,'f',2);
    finalCharge = QString::number(tempCharge,'f',2);

    ui->lbChargeWeight->setText(finalWeight+" Kg");
    ui->lbChargeMoney->setText("Rp. "+finalCharge);
}

void CheckInController::on_btnRemove_clicked()
{
    // WEIGHT RE-CALCULATION
    QString weightLost = ui->listWeight->currentItem()->text();
    weightLost = weightLost.right(weightLost.length()-weightLost.indexOf("[")-1);
    weightLost = weightLost.left(weightLost.length()-4);

    QString currentWeight= ui->lbChargeWeight->text();
    currentWeight = currentWeight.left(currentWeight.length()-3);

    double tempInput = weightLost.toDouble();
    double tempWeight = currentWeight.toDouble();
    double tempCharge;

    qDebug() << QString::number(tempInput) << endl;
    qDebug() << QString::number(tempWeight) << endl;

    tempWeight = tempWeight - tempInput;
    tempCharge = (tempWeight - 20.00)*20000;

    if (tempCharge < 0){tempCharge = 0;}

    QString finalWeight = QString::number(tempWeight,'f',2);
    QString finalCharge = QString::number(tempCharge,'f',2);

    ui->lbChargeWeight->setText(finalWeight+" Kg");
    ui->lbChargeMoney->setText("Rp. "+finalCharge);

    // ITEM REMOVAL
    QListWidgetItem* item = ui->listWeight->takeItem(ui->listWeight->currentRow());
    delete item;
}

void CheckInController::on_btnRemoveAll_clicked()
{
    QMessageBox::StandardButton messagebox;
    messagebox = QMessageBox::warning(this,tr("Confirmation"),tr("Do you want to remove ALL Luggage? "),QMessageBox::Ok|QMessageBox::Abort);

    if (messagebox == QMessageBox::Abort){
        // DO NOTHING
    } else if(messagebox == QMessageBox::Ok){
        ui->listWeight->clear();
        ui->lbChargeWeight->setText("0.00 Kg");
        ui->lbChargeMoney->setText("Rp. 0.00");
    }
}

void CheckInController::on_btnCheck_clicked()
{
    QString tempInfo = ui->listPassenger->currentItem()->text();
    QString idpemesanan = tempInfo.mid(1,1);
    QString passName = tempInfo.right(tempInfo.length()-3);
    qDebug() << passName << endl;
    QList<Penumpang> penumpang = DbFactory::getPenumpangModel()->getPenumpangBy("nama=\""+passName+"\" AND id_pemesanan="+idpemesanan);
    QList<Penerbangan> penerbangan = DbFactory::getPenerbanganModel()->getPenerbanganBy2("pemesanan.id_penerbangan=penerbangan.id AND pemesanan.id="+idpemesanan);

    qDebug() << penumpang.length() << endl;
    qDebug() << penerbangan.length() << endl;

    if(penumpang.length()!=0 && penerbangan.length()!= 0){

        Penumpang pen =  penumpang.at(0);
        Penerbangan flight = penerbangan.at(0);
        ui->lbNama->setText(pen.titel+" "+pen.nama);
        ui->lbFlightNumber->setText(QString::number(flight.id));
        ui->lbSchedule->setText(getAirportCode(flight.id_bandara_asal)+" -> "+getAirportCode(flight.id_bandara_tujuan));
        ui->lbBoardingTime->setText(flight.jam_berangkat);
        ui->lbGate->setText("B");

        QString tempseat = DbFactory::getPenumpangModel()->getSeatNumberBy("pemesanan.id=penumpang.id_pemesanan AND pemesanan.id="+idpemesanan);
        ui->lbSeat->setText(tempseat);
    }

}

