#ifndef PENUMPANG_H
#define PENUMPANG_H

#include <QString>
#include <QVariant>

class Penumpang
{
public:
    Penumpang(qint32 id, qint32 id_pemesanan, QString titel, QString nama,
              qint32 is_checkin, QString no_kursi);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    qint32  id_pemesanan;
    QString titel;
    QString nama;
    qint32  is_checkin;
    QString no_kursi;
};

#endif // PENUMPANG_H
