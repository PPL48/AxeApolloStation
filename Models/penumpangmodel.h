#ifndef PENUMPANGMODEL_H
#define PENUMPANGMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/penumpang.h"

class PenumpangModel : public QSqlQueryModel
{
public:
    PenumpangModel(QObject* parent);

    //-- operation
    QList<Penumpang>  getAllPenumpang();
    QList<Penumpang>  getPenumpangBy(QString criteria);
    QString           getSeatNumberBy(QString criteria);	
    bool              insertPenumpang(Penumpang penumpang);
    bool              updatePenumpang(int index, Penumpang penumpang);
    bool              refreshList();
};

#endif // PENUMPANGMODEL_H
