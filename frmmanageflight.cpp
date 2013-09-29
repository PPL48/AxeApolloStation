#include "frmmanageflight.h"
#include "ui_frmmanageflight.h"

frmManageFlight::frmManageFlight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmManageFlight)
{
    ui->setupUi(this);
}

frmManageFlight::~frmManageFlight()
{
    delete ui;
}
