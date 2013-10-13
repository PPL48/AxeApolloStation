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
    
private slots:
    void on_btnLogout_clicked();
    void on_btnSearch_clicked();

private:
    Ui::CheckInController *ui;
};

#endif // CHECKINCONTROLLER_H
