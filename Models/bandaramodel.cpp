#include "bandaramodel.h"

BandaraModel::BandaraModel(QObject *parent) : QSqlQueryModel(parent)
{

}

QList<Bandara> BandaraModel::getAllBandara() {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Bandara> retVal;

    if (db.isOpen()) {
        QString theQuery = "SELECT * FROM bandara";
        setQuery(theQuery, db);

        int length = rowCount();

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

QList<Bandara> BandaraModel::getBandaraBy(QString criteria)
{
    QList<Bandara> pList;
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");

    if (db.isOpen()) {
        QSqlQuery query(db);
        query.exec("SELECT * FROM bandara where "+criteria);
        while(query.next()) {
            Bandara bandara(query.value("id").toInt(),query.value("nama").toString(),query.value("kode").toString(),
                            query.value("biaya").toInt());
            pList.push_back(bandara);
        }
    }
    return pList;
}

Bandara BandaraModel::getCache(int index) {
    return Bandara(record(index).value("id").toInt(),
                   record(index).value("nama").toString(),
                   record(index).value("kode").toString(),
                   record(index).value("biaya").toInt());
}
