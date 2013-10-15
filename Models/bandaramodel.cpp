#include "bandaramodel.h"

BandaraModel::BandaraModel(QObject *parent) : QSqlQueryModel(parent)
{

}

QList<Bandara> BandaraModel::getAllBandara() {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Bandara> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT * FROM bandara";
        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            Bandara bandara(record(i).value("id").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("kode").toString(),
                        record(i).value("biaya").toInt());
            retVal.push_back(bandara);
        }
    }
    return retVal;
}

QList<Bandara> BandaraModel::getBandaraBy(QString criteria) {

}

Bandara BandaraModel::getCache(int index) {
    return Bandara(record(index).value("id").toInt(),
                   record(index).value("nama").toString(),
                   record(index).value("kode").toString(),
                   record(index).value("biaya").toInt());
}
