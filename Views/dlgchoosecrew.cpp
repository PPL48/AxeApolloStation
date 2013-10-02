#include "dlgchoosecrew.h"
#include "ui_dlgchoosecrew.h"

dlgChooseCrew::dlgChooseCrew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgChooseCrew)
{
    ui->setupUi(this);
}

dlgChooseCrew::~dlgChooseCrew()
{
    delete ui;
}
