#include "dlgchoosecrew.h"
#include "ui_dlgchoosecrew.h"

#include "dbfactory.h"

DlgChooseCrew::DlgChooseCrew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgChooseCrew)
{
    ui->setupUi(this);

    m_Pegawai = DbFactory::instance()->getPegawaiModel()->getPegawaiBy("kode_job='CABIN'");

    foreach (Pegawai pgw, m_Pegawai) {
        ui->lvCrew->addItem(pgw.toString());
    }
    connect(ui->lvCrew, SIGNAL(currentRowChanged(int)), this, SLOT(print_crew(int)));
}

DlgChooseCrew::~DlgChooseCrew()
{
    delete ui;
}

void DlgChooseCrew::print_crew(int index) {
    Pegawai pgw = m_Pegawai.at(index);

    ui->lbIDNumber->setText(QString::number(pgw.getID()));
    ui->lbName->setText(pgw.getNama());
}

void DlgChooseCrew::on_buttons_accepted()
{
    Pegawai pgw = m_Pegawai.at(ui->lvCrew->currentIndex().row());

    emit choose_crew(pgw);
    this->hide();

    QObject::deleteLater();
}

void DlgChooseCrew::on_buttons_rejected()
{
    this->hide();
    QObject::deleteLater();
}
