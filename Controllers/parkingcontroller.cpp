#include "ParkingController.h"
#include "ui_parkingcontroller.h"

#include "viewfactory.h"
#include "dbfactory.h"
#include "Models/penerbanganmodel.h"

#include <QTextStream>
#include <QStandardItem>
#include <QStandardItemModel>

ParkingController::ParkingController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParkingController)
{
    ui->setupUi(this);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_clicked(int)));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox2_clicked(int)));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox3_clicked(int)));

    QList<QString> daysList;
    daysList.append("All");

    QList<QString> monthsList;
    monthsList.append("All");

    QList<QString> yearsList;
    yearsList.append("All");
    for ( int x = STR_YEAR; x <= CUR_YEAR; x++ ) {
        yearsList.append(QString::number(x));
    }

    /* Populate the comboBox */
    ui->comboBox->addItems(daysList);
    ui->comboBox_2->addItems(monthsList);
    ui->comboBox_3->addItems(yearsList);

    span_schedule = QList<QString>();
    span_range = QList<int>();

}

ParkingController::~ParkingController()
{
    delete ui;
}

int ParkingController::calculateDateDiff(QString dbefore, QString dafter){
    //decompose
    QTextStream out(stdout);
    //out << "dbefore=" + dbefore + ", dafter=" + dafter + "\n";
    int year_before = dbefore.left(4).toInt(); //out << "..year_before=" + QString::number(year_before) + "\n";
    int month_before = dbefore.mid(5, 2).toInt(); //out << "..month_before=" + QString::number(month_before) + "\n";
    int day_before = dbefore.right(2).toInt(); //out << "..day_before=" + QString::number(day_before) + "\n";
    int year_after = dafter.left(4).toInt(); //out << "..year_after=" + QString::number(year_after) + "\n";
    int month_after = dafter.mid(5, 2).toInt(); //out << "..month_after=" + QString::number(month_after) + "\n";
    int day_after = dafter.right(2).toInt(); //out << "..day_after=" + QString::number(day_after) + "\n";
    int year_diff = 0;
    int day_diff = 0;

    if (year_after != year_before){
        year_diff += year_after - year_before - 1;
    }
    if (month_after != month_before){
        int dummy_month_after;
        if (month_after > month_before){
            dummy_month_after = month_after;
        } else {
            dummy_month_after = 12 + month_after;
        }
        for (int x = dummy_month_after - 1; x > month_before; x--){
            if (dummy_month_after % 12 == 4 ||
                dummy_month_after % 12 == 6 ||
                dummy_month_after % 12 == 9 ||
                dummy_month_after % 12 == 11){
                day_diff += 30;
            } else if (dummy_month_after % 12 == 2) {
                day_diff += 28;
            } else {
                day_diff += 31;
            }
        }
    } else {
        if (year_diff > 0){
            day_diff += 365;
        }
    }
    if (day_after != day_before){
        if (month_after != month_before){
            if (month_before == 4 ||
                month_before == 6 ||
                month_before == 9 ||
                month_before == 11){
                day_diff += (30 + day_after - day_before);
            } else if (month_before == 2){
                day_diff += (28 + day_after - day_before);
            } else {
                day_diff += (31 + day_after - day_before);
            }
        } else {
            day_diff += day_after - day_before;
        }
    }
    if (day_diff < 0){
        return -1;
    } else {
        return (year_diff*365 + day_diff);
    }
}

void ParkingController::populateSpanTime(QList<Penerbangan> ql)
{
    QTextStream out(stdout);
    span_schedule.clear();
    span_range.clear();
    for (int x = 0; x < ql.length(); x++){
        int idx_last_this_plane = -1;
        int this_plane = ql.value(x).getPesawat_id();
        //out << "process row " + QString::number(x) + ", pesawat_id=" + QString::number(this_plane) + "\n";
        for (int y = (x - 1); y >= 0; y--){
            if (ql.value(y).getPesawat_id() == this_plane){
                idx_last_this_plane = y;
                break;
            }
        }
        if (idx_last_this_plane == -1){
            //out << "--no previous flight is found\n";
            QString mulai_parkir = ql.value(x).getTanggal() + "(00:00)";
            QString selesai_parkir = ql.value(x).getTanggal() + "(" + ql.value(x).getJam_berangkat() + ")";
            span_schedule.append(mulai_parkir + " - " + selesai_parkir);

            int hh_mulai_parkir = 0;
            int hh_selesai_parkir = ql.value(x).getJam_berangkat().left(2).toInt();
            span_range.append(hh_selesai_parkir - hh_mulai_parkir);

        } else {
            //out << "--previous flight is found\n";
            QString mulai_parkir = ql.value(idx_last_this_plane).getTanggal() + "(" + ql.value(idx_last_this_plane).getJam_tiba() + ")";
            QString selesai_parkir = ql.value(x).getTanggal() + "(" + ql.value(x).getJam_berangkat() + ")";
            span_schedule.append(mulai_parkir + " - " + selesai_parkir);

            int hh_mulai_parkir = ql.value(idx_last_this_plane).getJam_tiba().left(2).toInt();
            int hh_selesai_parkir = ql.value(x).getJam_berangkat().left(2).toInt();
            int date_diff = calculateDateDiff(ql.value(idx_last_this_plane).getTanggal(), ql.value(x).getTanggal());
            //out << "----date_diff=" + QString::number(date_diff) + "\n";
            if (hh_selesai_parkir - hh_mulai_parkir < 0){
                if (date_diff > 0){
                    span_range.append(date_diff * 24 + hh_selesai_parkir - hh_mulai_parkir);
                } else {
                    span_range.append(-1);
                }
            } else {
                span_range.append(date_diff * 24 + hh_selesai_parkir - hh_mulai_parkir);
            }
        }
    }
}

void ParkingController::on_comboBox_clicked(int index)
{
    QTextStream out(stdout);
    if (index >= 0){
        out << "day " + QString::number(index) + " is selected\n";

        int yearParam;
        if (ui->comboBox_3->currentIndex() == 0){
            yearParam = 0;
        } else {
            yearParam = ui->comboBox_3->currentText().toInt();
        }

        QList<Penerbangan> pbgnList = DbFactory::getPenerbanganModel()->getPenerbangan(ui->comboBox->currentIndex(),
                                                                                       ui->comboBox_2->currentIndex(),
                                                                                       yearParam);
        populateSpanTime(pbgnList);
        while (ui->tableWidget->rowCount() > 0)
        {
            ui->tableWidget->removeRow(0);
        }
        ui->tableWidget->setRowCount(pbgnList.length());
        ui->tableWidget->setColumnCount(6);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Time Range"));
        ui->tableWidget->setColumnWidth(0, 220);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Hour(s)"));
        ui->tableWidget->setColumnWidth(1, 60);
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Airport"));
        ui->tableWidget->setColumnWidth(2, 60);
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Fee/Hour"));
        ui->tableWidget->setColumnWidth(3, 60);
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Payment"));
        ui->tableWidget->setColumnWidth(4, 60);
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Airplane"));
        ui->tableWidget->setColumnWidth(5, 120);

        for (int x = 0; x < span_schedule.length(); x++){
            ui->tableWidget->setItem(x, 0, new QTableWidgetItem(span_schedule.value(x)));
            ui->tableWidget->setItem(x, 1, new QTableWidgetItem(QString::number(span_range.value(x))));
        }
        int sum = 0;
        for (int x = 0; x < pbgnList.length(); x++){
            int id_airport = pbgnList.value(x).getBandara_asal_id();
            int id_pesawat = pbgnList.value(x).getPesawat_id();
            int cost_airport = DbFactory::getPenerbanganModel()->getTarifParkirBandaraById(id_airport);
            int span_time = ui->tableWidget->item(x, 1)->text().toInt();
            ui->tableWidget->setItem(x, 2, new QTableWidgetItem(DbFactory::getPenerbanganModel()->getBandaraById(id_airport)));
            ui->tableWidget->setItem(x, 3, new QTableWidgetItem(QString::number(cost_airport)));
            ui->tableWidget->setItem(x, 4, new QTableWidgetItem(QString::number(span_time * cost_airport)));
            ui->tableWidget->setItem(x, 5, new QTableWidgetItem(DbFactory::getPenerbanganModel()->getPesawatById(id_pesawat)));
            sum += (span_time * cost_airport);
        }
        ui->label_5->setText(QString::number(sum));
    }
}
void ParkingController::on_comboBox2_clicked(int index)
{
    QTextStream out(stdout);
    if (index >= 0){
        out << "month " + QString::number(index) + " is selected\n";

        if (index == 0){
            ui->comboBox->clear();
            ui->comboBox->addItem("All");
        } else {
            ui->comboBox->clear();
            ui->comboBox->addItem("All");
            if (index == 4 || index == 6 || index == 9 || index == 11){
                QList<QString> daysList;
                for ( int x = 1; x <= 30; x++ ) {
                    daysList.append(QString::number(x));
                }
                ui->comboBox->addItems(daysList);
            } else if (index == 2) {
                QList<QString> daysList;
                for ( int x = 1; x <= 28; x++ ) {
                    daysList.append(QString::number(x));
                }
                ui->comboBox->addItems(daysList);

            } else {
                QList<QString> daysList;
                for ( int x = 1; x <= 31; x++ ) {
                    daysList.append(QString::number(x));
                }
                ui->comboBox->addItems(daysList);
            }
        }
    }
}
void ParkingController::on_comboBox3_clicked(int index)
{
    QTextStream out(stdout);
    if (index >= 0){
        out << "year " + QString::number(index) + " is selected\n";
        if (index == 0){
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("All");

        } else {
            ui->comboBox_2->clear();
            ui->comboBox_2->addItem("All");

            QList<QString> monthsList;
            monthsList.append("January");
            monthsList.append("February");
            monthsList.append("March");
            monthsList.append("April");
            monthsList.append("May");
            monthsList.append("June");
            monthsList.append("July");
            monthsList.append("August");
            monthsList.append("September");
            monthsList.append("October");
            monthsList.append("November");
            monthsList.append("December");
            ui->comboBox_2->addItems(monthsList);
        }
    }
}
void ParkingController::on_btnLogout_clicked()
{
    //-- Save all credentials

    //-- Clear

    //-- back to login form
    if (true)
        ViewFactory::swapUI(vwLogin);
}
