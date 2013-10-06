#ifndef BAGASIMODEL_H
#define BAGASIMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/bagasi.h"

class BagasiModel : public QSqlQueryModel
{
public:
    BagasiModel(QObject* parent);

    //-- operation
    bool insertBagasi(Bagasi bagasi);
    bool updateBagasi(int index, Bagasi bagasi);
};

#endif // BAGASIMODEL_H
