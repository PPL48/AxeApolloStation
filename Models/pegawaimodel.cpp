#include "pegawaimodel.h"

PegawaiModel::PegawaiModel(QObject *parent) : QSqlQueryModel(parent)
{
    //setQuery("select * from pegawai");
}


QList<Pegawai> PegawaiModel::getPegawaiBy(QString criteria) {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Pegawai> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT * FROM pegawai WHERE ";
        theQuery.append(criteria);

        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            Pegawai pegawai(record(i).value("id").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("kode_job").toString());
            retVal.push_back(pegawai);
        }
    }
    return retVal;
}

QMap<int, Pegawai> PegawaiModel::getAviatorMappedID() {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QMap<int, Pegawai> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT * FROM pegawai WHERE kode_job='PILOT'";
        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            Pegawai pegawai(record(i).value("id").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("kode_job").toString());
            retVal.insert(pegawai.getID(),pegawai);
        }
    }
    return retVal;
}

QMap<int, Pegawai> PegawaiModel::getCrewMappedID() {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QMap<int, Pegawai> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT * FROM pegawai WHERE kode_job='CABIN'";
        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            Pegawai pegawai(record(i).value("id").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("kode_job").toString());
            retVal.insert(pegawai.getID(),pegawai);
        }
    }
    return retVal;
}
