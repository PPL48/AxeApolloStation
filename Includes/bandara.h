#ifndef BANDARA_H
#define BANDARA_H

#include <QString>
#include <QVariant>

class Bandara
{
public:
    Bandara();
    Bandara(qint32 id, QString nama, QString kode, qint32 biaya);
    void set(qint32 id, QString nama, QString kode, qint32 biaya);
    void set(const Bandara& bandara);

    QString  toString();
    int      getID();
    QString  getNama();
    QString  getKode();
    int      getBiaya();

//private:
    qint32   id;
    QString  nama;
    QString  kode;
    qint32   biaya;
};

#endif // BANDARA_H
