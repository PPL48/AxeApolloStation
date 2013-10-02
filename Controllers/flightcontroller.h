#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include <QMainWindow>

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

private:
    Ui::FlightController *ui;
};

#endif // FLIGHTCONTROLLER_H
