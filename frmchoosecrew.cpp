#include "frmchoosecrew.h"
#include "ui_frmchoosecrew.h"

frmChooseCrew::frmChooseCrew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmChooseCrew)
{
    ui->setupUi(this);
}

frmChooseCrew::~frmChooseCrew()
{
    delete ui;
}
