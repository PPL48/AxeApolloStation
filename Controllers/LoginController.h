#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QMainWindow>

namespace Ui {
class LoginController;
}

class LoginController : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LoginController(QWidget *parent = 0);
    ~LoginController();
    
private:
    Ui::LoginController *ui;

private slots:
    void check_credentials();
    void on_rbShowPass_clicked(bool checked);
};

#endif // LOGINCONTROLLER_H
