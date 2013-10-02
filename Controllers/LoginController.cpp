#include "logincontroller.h"
#include "ui_logincontroller.h"

#include "viewfactory.h"

LoginController::LoginController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginController)
{
    ui->setupUi(this);

    connect (ui->btnQuit, SIGNAL(clicked()),qApp, SLOT(quit()));
    connect (ui->btnLogin, SIGNAL(clicked()), this, SLOT(check_credentials()));

    connect (ui->rbShowPass, SIGNAL(clicked(bool)), this, SLOT(on_rbShowPass_clicked(bool)));
}

void LoginController::check_credentials() {
    // Get Controller instance

    // Query

    // Get result

    if (true) {
        ViewType vt;
        switch (ui->cbRole->currentIndex()) {
        case 0:
            vt = vwCheckIn;
            break;
        case 1:
            vt = vwFlight;
            break;
        case 2:
            vt = vwParking;
            break;
        }

        ViewFactory::swapUI(vt);
    }
}

LoginController::~LoginController()
{
    delete ui;
}

//-- SLOTS ---
void LoginController::on_rbShowPass_clicked(bool checked) {
    if (checked)
        ui->edPassword->setEchoMode(QLineEdit::Normal);
    else
        ui->edPassword->setEchoMode(QLineEdit::Password);
}
