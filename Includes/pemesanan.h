#ifndef PEMESANAN_H
#define PEMESANAN_H

#include <QString>
#include <QVariant>

class Pemesanan
{
public:
    Pemesanan(qint32  id, QString kode_booking, qint32  id_penerbangan);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString kode_booking;
    qint32  id_penerbangan;
};

#endif // PEMESANAN_H
