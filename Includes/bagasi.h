#ifndef BAGASI_H
#define BAGASI_H

#include <QString>
#include <QVariant>

class Bagasi
{
public:
    Bagasi(qint32 id, QString kode_bagasi,
           qint32 id_penumpang, qint32 berat,
           qint32 charge);

    QVariant toVariant();
    QString  toString();
private:
    qint32      id;
    QString     kode_bagasi;
    qint32      id_penumpang;
    qint32      berat;
    qint32      charge;
};

#endif // BAGASI_H
