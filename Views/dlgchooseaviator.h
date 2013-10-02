#ifndef DLGCHOOSEAVIATOR_H
#define DLGCHOOSEAVIATOR_H

#include <QDialog>

namespace Ui {
class dlgChooseAviator;
}

class dlgChooseAviator : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgChooseAviator(QWidget *parent = 0);
    ~dlgChooseAviator();
    
private:
    Ui::dlgChooseAviator *ui;
};

#endif // DLGCHOOSEAVIATOR_H
