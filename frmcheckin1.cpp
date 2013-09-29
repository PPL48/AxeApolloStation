#include "frmcheckin1.h"
#include "ui_frmcheckin1.h"

frmCheckIn1::frmCheckIn1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmCheckIn1)
{
    ui->setupUi(this);
}

frmCheckIn1::~frmCheckIn1()
{
    delete ui;
}
