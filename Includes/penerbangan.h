#ifndef PENERBANGAN_H
#define PENERBANGAN_H

#include <QString>
#include <QVariant>

class Penerbangan
{
public:
    Penerbangan(qint32  id, QString jam_berangkat, QString jam_tiba, QString tanggal,
        qint32  id_bandara_asal, qint32  id_bandara_tujuan, qint32  id_pesawat);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString jam_berangkat;
    QString jam_tiba;
    QString tanggal;
    qint32  id_bandara_asal;
    qint32  id_bandara_tujuan;
    qint32  id_pesawat;
};

#endif // PENERBANGAN_H
