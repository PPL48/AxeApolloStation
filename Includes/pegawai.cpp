#include "pegawai.h"

Pegawai::Pegawai() {
    id = 0;
    nama = "";
    kode_job = "";
}

Pegawai::Pegawai(qint32 a, QString b, QString c)
{
    id = a;
    nama = b;
    kode_job = c;
}

QString Pegawai::toString() const {
    return nama;
}

int Pegawai::getID() {
    return id;
}

QString Pegawai::getNama() {
    return nama;
}

QString Pegawai::getJob() {
    return kode_job;
}

bool Pegawai::operator==(const Pegawai& pegawai) {
    return (id==pegawai.id)&&(nama==pegawai.nama)&&(kode_job==pegawai.kode_job);
}

Pegawai& Pegawai::operator=(const Pegawai& pegawai) {
    id=pegawai.id;
    nama=pegawai.nama;
    kode_job=pegawai.kode_job;

    return *this;
}
/*
QDebug operator<<(QDebug d, const Pegawai& pgw) {
    d << pgw.toString();
    return d;
}
*/
