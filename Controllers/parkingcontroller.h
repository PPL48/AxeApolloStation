#ifndef PARKINGCONTROLLER_H
#define PARKINGCONTROLLER_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <Includes/penerbangan.h>
#define STR_YEAR 2013
#define CUR_YEAR 2013

namespace Ui {
class ParkingController;
}

class ParkingController : public QMainWindow
{
    Q_OBJECT
    QList<QString> span_schedule;
    QList<int> span_range;

public:
    explicit ParkingController(QWidget *parent = 0);
    ~ParkingController();

    //--
    void calculateParking();
    
private slots:
    void on_btnLogout_clicked();
    void populateSpanTime(QList<Penerbangan> ql);
    int calculateDateDiff(QString dbefore, QString dafter);
    void on_comboBox_clicked(int index);
    void on_comboBox2_clicked(int index);
    void on_comboBox3_clicked(int index);

private:
    Ui::ParkingController *ui;
};

#endif // PARKINGCONTROLLER_H
