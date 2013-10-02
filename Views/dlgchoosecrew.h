#ifndef DLGCHOOSECREW_H
#define DLGCHOOSECREW_H

#include <QDialog>

namespace Ui {
class dlgChooseCrew;
}

class dlgChooseCrew : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgChooseCrew(QWidget *parent = 0);
    ~dlgChooseCrew();
    
private:
    Ui::dlgChooseCrew *ui;
};

#endif // DLGCHOOSECREW_H
