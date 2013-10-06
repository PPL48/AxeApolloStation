#ifndef DLGCHOOSECREW_H
#define DLGCHOOSECREW_H

#include <QDialog>

namespace Ui {
class DlgChooseCrew;
}

class DlgChooseCrew : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgChooseCrew(QWidget *parent = 0);
    ~DlgChooseCrew();
    
private:
    Ui::DlgChooseCrew *ui;
};

#endif // DLGCHOOSECREW_H
