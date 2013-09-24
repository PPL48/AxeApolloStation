#include "frmlogin.h"
#include "ui_frmlogin.h"

frmLogin::frmLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmLogin)
{
    ui->setupUi(this);
}

frmLogin::~frmLogin()
{
    delete ui;
}
