#include "dlgchooseaviator.h"
#include "ui_dlgchooseaviator.h"

#include "dbfactory.h"
#include "Includes/pegawai.h"

DlgChooseAviator::DlgChooseAviator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgChooseAviator)
{
    ui->setupUi(this);

    m_Pegawai = DbFactory::instance()->getPegawaiModel()->getPegawaiBy("kode_job='PILOT'");

    foreach (Pegawai pgw, m_Pegawai) {
        ui->lvAviator->addItem(pgw.toString());
    }
    connect(ui->lvAviator, SIGNAL(currentRowChanged(int)), this, SLOT(print_aviator(int)));
}

void DlgChooseAviator::print_aviator(int index) {
    Pegawai pgw = m_Pegawai.at(index);

    ui->lbIDNumber->setText(pgw.getID());
    ui->lbName->setText(pgw.getNama());
}

DlgChooseAviator::~DlgChooseAviator()
{
    delete ui;
}

void DlgChooseAviator::on_buttons_accepted()
{
    Pegawai pgw = m_Pegawai.at(ui->lvAviator->currentIndex().row());

    emit choose_aviator(pgw);
    this->hide();
}
