#include "pesawatmodel.h"

#include <QDebug>

PesawatModel::PesawatModel(QObject *parent) : QSqlQueryModel(parent)
{

}

QList<Pesawat> PesawatModel::getAllPesawat() {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Pesawat> retVal;
    retVal.clear();

    if (db.isOpen()) {
        setQuery("SELECT * FROM pesawat", db);

        int length = rowCount();

        for(int i=0; i<length; ++i) {
            Pesawat pswt(record(i).value("id").toInt(),
                         record(i).value("nama").toString(),
                         record(i).value("total_kursi").toInt());
            retVal.push_back(pswt);
        }
    }

    return retVal;
}
