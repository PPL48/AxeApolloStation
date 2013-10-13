#ifndef PEGAWAI_H
#define PEGAWAI_H

#include <QString>
#include <QVariant>

class Pegawai
{
public:
    Pegawai(qint32 id, QString nama, QString kode_job);

    QVariant toVariant();
    QString  toString();

    QString  getID();
    QString  getNama();
    QString  getJob();

private:
    qint32  id;
    QString nama;
    QString  kode_job;
};

#endif // PEGAWAI_H
