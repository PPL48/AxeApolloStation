#include "pesawat.h"

Pesawat::Pesawat() {
    id = -1;
    nama = "";
    total_kursi = -1;
}

Pesawat::Pesawat(qint32 a, QString b, qint32 c)
{
    id = a;
    nama = b;
    total_kursi = c;
}

void Pesawat::set(qint32 a, QString b, qint32 c)
{
    id = a;
    nama = b;
    total_kursi = c;
}

void Pesawat::set(const Pesawat& pesawat)
{
    id = pesawat.id;
    nama = pesawat.nama;
    total_kursi = pesawat.total_kursi;
}

QString Pesawat::toString() {
    return nama;
}

int Pesawat::getID() {
    return id;
}

QString Pesawat::getNama() {
    return nama;
}

int Pesawat::getKursi() {
    return total_kursi;
}
