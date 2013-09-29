#ifndef FRMCHECKIN1_H
#define FRMCHECKIN1_H

#include <QWidget>

namespace Ui {
class frmCheckIn1;
}

class frmCheckIn1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmCheckIn1(QWidget *parent = 0);
    ~frmCheckIn1();
    
private:
    Ui::frmCheckIn1 *ui;
};

#endif // FRMCHECKIN1_H
