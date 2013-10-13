#include "bandara.h"

Bandara::Bandara(qint32 a, QString b, QString c, qint32 d)
{
    id = a;
    nama = b;
    kode = c;
    biaya = d;
}

QString Bandara::toString() {
    return nama;
}
