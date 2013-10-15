#ifndef PEGAWAI_H
#define PEGAWAI_H

#include <QString>
#include <QVariant>
#include <QDebug>

class Pegawai
{
public:
    Pegawai();
    Pegawai(qint32 id, QString nama, QString kode_job);

    QString  toString() const;

    int      getID();
    QString  getNama();
    QString  getJob();

    bool     operator==(const Pegawai& pegawai);
    Pegawai& operator=(const Pegawai& pegawai);

    /*friend QDebug operator<<(QDebug d, const Pegawai& pgw);*/

private:
    qint32  id;
    QString nama;
    QString kode_job;
};

#endif // PEGAWAI_H
