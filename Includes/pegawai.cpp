#include "pegawai.h"

Pegawai::Pegawai(qint32 a, QString b, QString c)
{
    id = a;
    nama = b;
    kode_job = c;
}

QString Pegawai::toString() {
    return nama;
}

QString Pegawai::getID() {
    return QString("%1").arg(id);
}

QString Pegawai::getNama() {
    return nama;
}

QString Pegawai::getJob() {
    return kode_job;
}
