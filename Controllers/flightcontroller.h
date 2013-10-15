#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include <QMainWindow>

#include "Includes/pegawai.h"
#include "Includes/penerbangan.h"

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
    void on_btnRefresh_clicked();
    void on_FlightManager_currentChanged(int index);
    void on_lvPenerbangan_clicked(const QModelIndex &index);

private:
    Ui::FlightController *ui;

    QList<Pegawai>     m_Aviator;
    QList<Pegawai>     m_Crew;

    QList<Penerbangan>            m_Penerbangan;
    QMap< int, QList<Pegawai> >   m_AviatorShow;    // <id_penerbangan, list of pegawai>
    QMap< int, QList<Pegawai> >   m_CrewShow;
};

#endif // FLIGHTCONTROLLER_H
