#ifndef PEGAWAI_H
#define PEGAWAI_H

#include <QString>
#include <QVariant>

class Pegawai
{
public:
    Pegawai(qint32 id, QString nama, qint32 kode_job);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString nama;
    qint32  kode_job;
};

#endif // PEGAWAI_H
