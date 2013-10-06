#include "bagasi.h"

Bagasi::Bagasi(qint32 a, QString b, qint32 c, qint32 d, qint32 e)
{
    id = a;
    kode_bagasi = b;
    id_penumpang = c;
    berat = d;
    charge = e;
}

QString Bagasi::toString() {
    QString str("%1-%2-%3-%4");
    str.arg(kode_bagasi);
    str.arg(id_penumpang);
    str.arg(berat);
    str.arg(charge);
    return str;
}
