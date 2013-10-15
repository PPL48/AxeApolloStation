#ifndef PENERBANGAN_H
#define PENERBANGAN_H

#include <QString>
#include <QVariant>

class Penerbangan
{
public:
    Penerbangan(qint32  id, QString jam_berangkat, QString jam_tiba, QString tanggal,
        qint32  id_bandara_asal, qint32  id_bandara_tujuan, qint32  id_pesawat,
        QString bandara_asal, QString bandara_tujuan, QString pesawat);

    QVariant toVariant();
    QString  toString();

    int     getID();
    QString getDate();
    QString getAirportDepart();
    QString getAirportArrival();
    QString getPesawat();

private:
    qint32  id;
    QString jam_berangkat;
    QString jam_tiba;
    QString tanggal;
    qint32  id_bandara_asal;
    qint32  id_bandara_tujuan;
    qint32  id_pesawat;

    QString bandara_asal;
    QString bandara_tujuan;
    QString pesawat;
};

#endif // PENERBANGAN_H
