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
            Bandara pegawai(record(i).value("id").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("kode").toString(),
                        record(i).value("biaya").toInt());
            retVal.push_back(pegawai);
        }
    }
    return retVal;
}

QList<Bandara> BandaraModel::getBandaraBy(QString criteria) {

}
