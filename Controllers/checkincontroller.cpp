#include "CheckInController.h"
#include "ui_checkincontroller.h"

#include "viewfactory.h"
#include "dbfactory.h"
#include <QMessageBox>
#include "../Models/pemesanmodel.h"

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

Pemesan CheckInController::searchPemesanBy(QString criteria)
{
}

void CheckInController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}

void CheckInController::on_btnSearch_clicked(){
    QString resNum = ui->resNum->text();
    QString idCardNum = ui->idCardNum->text();

    QList<Pemesan> pemesan = DbFactory::getPemesanModel()->getPemesanBy("id_pemesanan=");
    if(pemesan.length()!=1){
        pemesan.clear();
        pemesan = DbFactory::getPemesanModel()->getPemesanBy("id="+idCardNum);
    }
    if(pemesan.length()!=1){
        QMessageBox::warning(this,tr("Search Failed"),tr("Reservation number / ID Card Number not found"),QMessageBox::Ok);
    }else{
        Pemesan p = pemesan.at(0);
        ui->lbIDNumber->setText(QString::number(p.id));
        ui->lbReserveNumber->setText(QString::number(p.id_pemesanan));
        ui->lbNama->setText(p.nama);
    }
}
