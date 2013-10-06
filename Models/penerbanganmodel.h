#ifndef PENERBANGANMODEL_H
#define PENERBANGANMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/penerbangan.h"

class PenerbanganModel : public QSqlQueryModel
{
public:
    PenerbanganModel(QObject* parent);

    //-- operation
    QList<Penerbangan>  getAllPenerbangan();
    QList<Penerbangan>  getPenerbanganBy(QString criteria);
    bool                createPenerbangan(Penerbangan penerbangan);
    bool                updatePenerbangan(int index, Penerbangan penerbangan);
    bool                refreshList();
};

#endif // PENERBANGANMODEL_H
