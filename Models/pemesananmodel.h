#ifndef PEMESANANMODEL_H
#define PEMESANANMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pemesanan.h"

class PemesananModel : public QSqlQueryModel
{
public:
    PemesananModel(QObject* parent);

    //-- operation
    Pemesanan   searchPemesananBy(QString criteria);
};

#endif // PEMESANANMODEL_H
