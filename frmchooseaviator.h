#ifndef FRMCHOOSEAVIATOR_H
#define FRMCHOOSEAVIATOR_H

#include <QWidget>

namespace Ui {
class frmChooseAviator;
}

class frmChooseAviator : public QWidget
{
    Q_OBJECT
    
public:
    explicit frmChooseAviator(QWidget *parent = 0);
    ~frmChooseAviator();
    
private:
    Ui::frmChooseAviator *ui;
};

#endif // FRMCHOOSEAVIATOR_H
