#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "frmlogin.h"
#include "frmcheckin1.h"
#include "frmcheckin2.h"
#include "frmchooseaviator.h"
#include "frmchoosecrew.h"
#include "frmmanageflight.h"

#include <QDebug>

QWidget* ll;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *login = new frmLogin;
    qDebug() << "Ukuran login " << login->size();
    QWidget *checkin1 = new frmCheckIn1;
    qDebug() << "Ukuran checkin1 " << checkin1->size();
    QWidget *checkin2 = new frmCheckIn2;
    qDebug() << "Ukuran checkin2 " << checkin2->size();
    QWidget *chooseaviator = new frmChooseAviator;
    qDebug() << "Ukuran aviator " << chooseaviator->size();
    QWidget *choosecrew = new frmChooseCrew;
    qDebug() << "Ukuran crew " << choosecrew->size();
    QWidget *manageflight = new frmManageFlight;
    qDebug() << "Ukuran flight " << manageflight->size();

    ui->widgets->addWidget(login);
    ui->widgets->addWidget(checkin1);
    ui->widgets->addWidget(checkin2);
    ui->widgets->addWidget(chooseaviator);
    ui->widgets->addWidget(choosecrew);
    ui->widgets->addWidget(manageflight);

    QWidget* child = ui->widgets->childAt(QPoint(0,0));
    ui->widgets->removeWidget(child);
    child = ui->widgets->childAt(QPoint(0,0));
    ui->widgets->removeWidget(child);

    ui->widgets->setCurrentIndex(0);

    qDebug() << ui->widgets->count();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->widgets->setCurrentIndex(index);

    QSize ukuranWidget, ukuranWindow;

    switch (index) {
    case 0:
        ukuranWidget = QSize(337, 121);
        break;
    case 1:
        ukuranWidget = QSize(400,300);
        break;
    case 2:
        ukuranWidget = QSize(640, 480);
        break;
    case 3:
        ukuranWidget = QSize(320, 480);
        break;
    case 4:
        ukuranWidget = QSize(320, 480);
        break;
    case 5:
        ukuranWidget = QSize(640, 480);
        break;
    }

    ukuranWindow = ukuranWidget + QSize(20, 80);

    ui->widgets->resize (ukuranWidget);
    resize (ukuranWindow);
}
