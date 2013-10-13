#ifndef BANDARA_H
#define BANDARA_H

#include <QString>
#include <QVariant>

class Bandara
{
public:
    Bandara(qint32 id, QString nama, QString kode, qint32 biaya);

    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString nama;
    QString  kode;
    qint32  biaya;
};

#endif // BANDARA_H
