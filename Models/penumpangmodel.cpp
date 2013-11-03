#include "penumpangmodel.h"

PenumpangModel::PenumpangModel(QObject *parent) : QSqlQueryModel(parent)
{
}

QList<Penumpang> PenumpangModel::getPenumpangBy(QString criteria)
{
    QList<Penumpang> pList;
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QSqlQuery query(db);
    query.exec("SELECT * FROM penumpang where "+criteria);
    while(query.next()) {
        Penumpang penumpang(query.value("id").toInt(),query.value("id_pemesanan").toInt(),query.value("titel").toString(),
                        query.value("nama").toString(),query.value("is_checkin").toInt(),
                        query.value("no_kursi").toString());
        pList.push_back(penumpang);
    }
    return pList;
}

QString PenumpangModel::getSeatNumberBy(QString criteria)
{
    QString result;
    QList<Penumpang> pList;
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QSqlQuery query(db);
    query.exec("SELECT * FROM penumpang,pemesanan where penumpang.no_kursi !=0 AND "+criteria);
    while(query.next()) {
        Penumpang penumpang(query.value("id").toInt(),query.value("id_pemesanan").toInt(),query.value("titel").toString(),
                        query.value("nama").toString(),query.value("is_checkin").toInt(),
                        query.value("no_kursi").toString());
        pList.push_back(penumpang);
    }

    result = QString::number(pList.length()+1);
    return result;
}

