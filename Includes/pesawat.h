#ifndef PESAWAT_H
#define PESAWAT_H

#include <QString>
#include <QVariant>

class Pesawat
{
public:
    Pesawat();
    Pesawat(qint32 id, QString nama, qint32 total_kursi);
    void set(qint32 id, QString nama, qint32 total_kursi);
    void set(const Pesawat& pesawat);

    QString  toString();

    int      getID();
    QString  getNama();
    int      getKursi();

private:
    qint32  id;
    QString nama;
    qint32  total_kursi;
};

#endif // PESAWAT_H
