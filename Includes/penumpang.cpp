#include "penumpang.h"

Penumpang::Penumpang(qint32 a, qint32 b, QString c, QString d, qint32 e, QString f)
{
    id = a;
    id_pemesanan = b;
    titel = c;
    nama = d;
    is_checkin = e;
    no_kursi = f;
}
