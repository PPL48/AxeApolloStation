#ifndef PEMESANMODEL_H
#define PEMESANMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pemesan.h"

class PemesanModel : public QSqlQueryModel
{
public:
    PemesanModel(QObject* parent);

    //-- operation
    QList<Pemesan>  getAllPemesan();
    QList<Pemesan>  getPemesanBy(QString criteria);
    bool            insertPemesan(Pemesan pemesan);
    bool            updatePemesan(int index, Pemesan pemesan);
    bool            refreshList();

};

#endif // PEMESANMODEL_H
