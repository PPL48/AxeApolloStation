#ifndef DLGCHOOSEAVIATOR_H
#define DLGCHOOSEAVIATOR_H

#include <QDialog>
#include "Includes/pegawai.h"

namespace Ui {
class DlgChooseAviator;
}

class DlgChooseAviator : public QDialog
{
    Q_OBJECT

public:
    explicit DlgChooseAviator(QWidget *parent = 0);
    ~DlgChooseAviator();

signals:
    void choose_aviator(Pegawai);
    
private:
    Ui::DlgChooseAviator *ui;
    QList<Pegawai>  m_Pegawai;

private slots:
    void print_aviator(int index);
    void on_buttons_accepted();
};

#endif // DLGCHOOSEAVIATOR_H
