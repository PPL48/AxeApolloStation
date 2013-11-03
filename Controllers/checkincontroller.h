#ifndef CHECKINCONTROLLER_H
#define CHECKINCONTROLLER_H

#include <QMainWindow>

#include "Includes/pemesan.h"

namespace Ui {
class CheckInController;
}

class CheckInController : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CheckInController(QWidget *parent = 0);
    ~CheckInController();

    //--
    Pemesan searchPemesanBy(QString criteria);
    bool    createPemesan(Pemesan pemesan);
    int     randInt(qint32 low, qint32 high);
    QString getAirportCode(qint32 id);
    
private slots:
    void on_btnLogout_clicked();
    void on_btnSearch_clicked();
    void on_cbAddLuggage_stateChanged(int arg1);
    void on_btnAddLuggage_clicked();
    void on_btnRemove_clicked();
    void on_btnRemoveAll_clicked();
    void on_btnCheck_clicked();

    void on_cbAddLuggage_toggled(bool checked);

private:
    Ui::CheckInController *ui;
};

#endif // CHECKINCONTROLLER_H
