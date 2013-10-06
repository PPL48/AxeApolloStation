#ifndef PESAWATMODEL_H
#define PESAWATMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pesawat.h"

class PesawatModel : public QSqlQueryModel
{
public:
    PesawatModel(QObject* parent);

    //-- operation
    QList<Pesawat>  getAllPesawat();
    QList<Pesawat>  getPesawatBy(QString criteria);
    bool            insertPesawat(Pesawat pesawat);
    bool            updatePesawat(int index, Pesawat pesawat);
    bool            refreshList();
};

#endif // PESAWATMODEL_H
