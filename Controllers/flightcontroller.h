#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include <QMainWindow>

#include "Includes/pegawai.h"

namespace Ui {
class FlightController;
}

class FlightController : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FlightController(QWidget *parent = 0);
    ~FlightController();
    
private slots:
    void on_btnAviAdd_clicked();
    void on_btnAviRemove_clicked();
    void on_btnLogout_clicked();
    void on_btnCreate_clicked();

private:
    Ui::FlightController *ui;

private slots:
    void on_return_index(Pegawai);
};

#endif // FLIGHTCONTROLLER_H
