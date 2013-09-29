#ifndef FRMCHECKIN2_H
#define FRMCHECKIN2_H

#include <QWidget>

namespace Ui {
class frmCheckIn2;
}

class frmCheckIn2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmCheckIn2(QWidget *parent = 0);
    ~frmCheckIn2();
    
private:
    Ui::frmCheckIn2 *ui;
};

#endif // FRMCHECKIN2_H
