#ifndef BANDARAMODEL_H
#define BANDARAMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/bandara.h"

class BandaraModel : public QSqlQueryModel
{
    void fetch();

public:
    BandaraModel(QObject* parent);

    //-- operation
    QList<Bandara>  getAllBandara();
    QList<Bandara>  getBandaraBy(QString criteria);
    Bandara         getCache(int index);
    bool            insertBandara(Bandara bandara);
    bool            updateBandara(int index, Bandara bandara);
    bool            refreshList();

};

#endif // BANDARAMODEL_H
