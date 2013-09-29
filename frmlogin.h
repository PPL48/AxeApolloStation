#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QWidget>

namespace Ui {
class frmLogin;
}

class frmLogin : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmLogin(QWidget *parent = 0);
    ~frmLogin();
    
private:
    Ui::frmLogin *ui;
};

#endif // FRMLOGIN_H
