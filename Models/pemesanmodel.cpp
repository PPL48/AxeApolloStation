#include "pemesanmodel.h"

PemesanModel::PemesanModel(QObject *parent) : QSqlQueryModel(parent)
{
}

QList<Pemesan> PemesanModel::getPemesanBy(QString criteria)
{
    QList<Pemesan> pList;
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    setQuery("SELECT * FROM pemesan,pemesanan where "+criteria, db);

    int length = rowCount();

    for (int i=0; i < length; i++) {
        Pemesan pemesan(record(i).value("id").toInt(),
                        record(i).value("id_pemesanan").toInt(),
                        record(i).value("nama").toString(),
                        record(i).value("email").toString(),
                        record(i).value("no_handphone").toString(),
                        record(i).value("is_member").toInt());
        pList.push_back(pemesan);
    }
    return pList;
}
