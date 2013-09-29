#ifndef FRMMANAGEFLIGHT_H
#define FRMMANAGEFLIGHT_H

#include <QWidget>

namespace Ui {
class frmManageFlight;
}

class frmManageFlight : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmManageFlight(QWidget *parent = 0);
    ~frmManageFlight();
    
private:
    Ui::frmManageFlight *ui;
};

#endif // FRMMANAGEFLIGHT_H
