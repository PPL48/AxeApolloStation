#include "dlgchooseaviator.h"
#include "ui_dlgchooseaviator.h"

dlgChooseAviator::dlgChooseAviator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgChooseAviator)
{
    ui->setupUi(this);
}

dlgChooseAviator::~dlgChooseAviator()
{
    delete ui;
}
