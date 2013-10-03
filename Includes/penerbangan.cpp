#include "penerbangan.h"

Penerbangan::Penerbangan(qint32 a, QString b, QString c, QString d, qint32 e, qint32  f, qint32 g)
{
    id = a;
    jam_berangkat = b;
    jam_tiba = c;
    tanggal = d;
    id_bandara_asal = e;
    id_bandara_tujuan = f;
    id_pesawat = g;
}
