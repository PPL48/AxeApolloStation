#include "logincontroller.h"
#include "ui_logincontroller.h"

#include "viewfactory.h"
#include <QTextStream>
#include <QMessageBox>

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
    QTextStream out(stdout);
    QString username = this->ui->edUsername->text();
    out << username + "\n";
    QString password = this->ui->edPassword->text();
    out << password + "\n";

    // Query

    // Get result

   // if (username.compare("timo")==0 && password.compare("timooenjoe")==0) {
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
        //diclear dulu mestinya
        ViewFactory::swapUI(vt);
   // } else {
     //   QMessageBox::warning(this,tr("Invalid Input"),tr("Wrong username or password!"),QMessageBox::Ok);
    //}
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
