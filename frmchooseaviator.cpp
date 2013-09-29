#include "frmchooseaviator.h"
#include "ui_frmchooseaviator.h"

frmChooseAviator::frmChooseAviator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmChooseAviator)
{
    ui->setupUi(this);
}

frmChooseAviator::~frmChooseAviator()
{
    delete ui;
}
