#ifndef DLGCHOOSECREW_H
#define DLGCHOOSECREW_H

#include <QDialog>
#include "Includes/pegawai.h"

namespace Ui {
class DlgChooseCrew;
}

class DlgChooseCrew : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgChooseCrew(QWidget *parent = 0);
    ~DlgChooseCrew();

signals:
    void choose_crew(Pegawai);
    
private:
    Ui::DlgChooseCrew *ui;
    QList<Pegawai>  m_Pegawai;

private slots:
    void print_crew(int index);
    void on_buttons_accepted();
    void on_buttons_rejected();
};

#endif // DLGCHOOSECREW_H
