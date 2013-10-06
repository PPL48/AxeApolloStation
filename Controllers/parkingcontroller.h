#ifndef PARKINGCONTROLLER_H
#define PARKINGCONTROLLER_H

#include <QMainWindow>

namespace Ui {
class ParkingController;
}

class ParkingController : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ParkingController(QWidget *parent = 0);
    ~ParkingController();

    //--
    void calculateParking();
    
private slots:
    void on_btnLogout_clicked();

private:
    Ui::ParkingController *ui;
};

#endif // PARKINGCONTROLLER_H
