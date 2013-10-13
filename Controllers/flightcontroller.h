#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include <QMainWindow>

#include <QList>
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
    void on_btnCrewAdd_clicked();
    void on_btnAviRemove_clicked();
    void on_btnCrewRemove_clicked();
    void on_btnLogout_clicked();
    void on_btnCreate_clicked();
    void return_index(Pegawai);

    void on_btnClear_clicked();

private:
    Ui::FlightController *ui;

    QList<Pegawai> m_Aviator;
    QList<Pegawai> m_Crew;
};

#endif // FLIGHTCONTROLLER_H
