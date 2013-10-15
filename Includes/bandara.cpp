#include "bandara.h"

Bandara::Bandara() {
    id = -1;
    nama = "b""";
    kode = "";
    biaya = -1;
}

Bandara::Bandara(qint32 a, QString b, QString c, qint32 d)
{
    id = a;
    nama = b;
    kode = c;
    biaya = d;
}

void Bandara::set(qint32 a, QString b, QString c, qint32 d) {
    id = a;
    nama = b;
    kode = c;
    biaya = d;
}

void Bandara::set(const Bandara& bandara) {
    id = bandara.id;
    nama = bandara.nama;
    kode = bandara.kode;
    biaya = bandara.biaya;
}

QString Bandara::toString() {
    return nama;
}

int Bandara::getID() {
    return id;
}

QString Bandara::getNama() {
    return nama;
}

QString Bandara::getKode() {
    return kode;
}

int Bandara::getBiaya() {
    return biaya;
}
