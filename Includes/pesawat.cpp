#include "pesawat.h"

Pesawat::Pesawat(qint32 a, QString b, qint32 c)
{
    id = a;
    nama = b;
    total_kursi = c;
}


QString Pesawat::toString() {
    return nama;
}
