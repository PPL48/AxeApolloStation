#ifndef FRMCHOOSECREW_H
#define FRMCHOOSECREW_H

#include <QWidget>

namespace Ui {
class frmChooseCrew;
}

class frmChooseCrew : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmChooseCrew(QWidget *parent = 0);
    ~frmChooseCrew();
    
private:
    Ui::frmChooseCrew *ui;
};

#endif // FRMCHOOSECREW_H
