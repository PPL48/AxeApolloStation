#ifndef PESAWAT_H
#define PESAWAT_H

#include <QString>
#include <QVariant>

class Pesawat
{
public:
    Pesawat(qint32 id, QString nama, qint32 total_kursi);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString nama;
    qint32  total_kursi;
};

#endif // PESAWAT_H
