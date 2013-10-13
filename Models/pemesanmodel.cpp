#include "pemesanmodel.h"

PemesanModel::PemesanModel(QObject *parent) : QSqlQueryModel(parent)
{
}

QList<Pemesan> PemesanModel::getPemesanBy(QString criteria)
{
    QList<Pemesan> pList;
    QSqlQuery query;
    query.exec("SELECT * FROM pemesan where "+criteria);
    while(query.next()) {
        Pemesan pemesan(query.value("id").toInt(),query.value("id_pemesanan").toInt(),query.value("nama").toString(),
                        query.value("email").toString(),query.value("no_handphone").toString(),
                        query.value("is_member").toInt());
        pList.push_back(pemesan);
    }
    return pList;
}
