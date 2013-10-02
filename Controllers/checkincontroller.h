#ifndef CHECKINCONTROLLER_H
#define CHECKINCONTROLLER_H

#include <QMainWindow>

namespace Ui {
class CheckInController;
}

class CheckInController : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CheckInController(QWidget *parent = 0);
    ~CheckInController();
    
private slots:
    void on_btnLogout_clicked();

private:
    Ui::CheckInController *ui;
};

#endif // CHECKINCONTROLLER_H
