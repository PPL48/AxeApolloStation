#include "penerbangan.h"

Penerbangan::Penerbangan(qint32 a, QString b, QString c, QString d, qint32 e, qint32  f, qint32 g,
                         QString h, QString i, QString j)
{
    id = a;
    jam_berangkat = b;
    jam_tiba = c;
    tanggal = d;
    id_bandara_asal = e;
    id_bandara_tujuan = f;
    id_pesawat = g;

    bandara_asal = h;
    bandara_tujuan = i;
    pesawat = j;
}


QString Penerbangan::toString() {
    QString str = tanggal+" "+bandara_asal+"("+jam_berangkat+") to "+
            bandara_tujuan+"("+jam_tiba+")";
    return str;
}

int Penerbangan::getID() {
    return id;
}

QString Penerbangan::getDate() {
    return tanggal;
}

QString Penerbangan::getAirportDepart() {
    return bandara_asal;
}

QString Penerbangan::getAirportArrival() {
    return bandara_tujuan;
}

QString Penerbangan::getPesawat() {
    return pesawat;
}
