#include "dlgchoosecrew.h"
#include "ui_dlgchoosecrew.h"

DlgChooseCrew::DlgChooseCrew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgChooseCrew)
{
    ui->setupUi(this);
}

DlgChooseCrew::~DlgChooseCrew()
{
    delete ui;
}
