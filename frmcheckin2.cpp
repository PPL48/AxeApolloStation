#include "frmcheckin2.h"
#include "ui_frmcheckin2.h"

frmCheckIn2::frmCheckIn2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmCheckIn2)
{
    ui->setupUi(this);
}

frmCheckIn2::~frmCheckIn2()
{
    delete ui;
}
