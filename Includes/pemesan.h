#ifndef PEMESAN_H
#define PEMESAN_H

#include <QString>
#include <QVariant>

class Pemesan
{
public:
    Pemesan(qint32  id, qint32  id_pemesanan, QString nama, QString email,
            QString no_handphone, qint32  is_member);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    qint32  id_pemesanan;
    QString nama;
    QString email;
    QString no_handphone;
    qint32  is_member;
};

#endif // PEMESAN_H
