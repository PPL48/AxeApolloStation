#include "penerbanganmodel.h"

PenerbanganModel::PenerbanganModel(QObject *parent) : QSqlQueryModel(parent)
{

}


QList<Penerbangan> PenerbanganModel::getAllPenerbangan()
{
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Penerbangan> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT pnb.id as id, pnb.jam_berangkat as jam_berangkat, pnb.jam_tiba as jam_tiba, "
                                  "pnb.tanggal as tanggal, pnb.id_bandara_asal as id_bandara_asal, pnb.id_bandara_tujuan as id_bandara_tujuan, "
                                  "pnb.id_pesawat as id_pesawat, bdr1.nama as bandara_asal, bdr2.nama as bandara_tujuan, pswt.nama as pesawat "
                           "FROM penerbangan as pnb, bandara as bdr1, bandara as bdr2, pesawat as pswt "
                           "WHERE pnb.id_bandara_asal = bdr1.id AND pnb.id_bandara_tujuan = bdr2.id AND pnb.id_pesawat = pswt.id";
        setQuery(theQuery, db);

        int length = rowCount();

        for (int i=0; i<length; ++i) {
            Penerbangan penerbangan(
                        record(i).value("id").toInt(),
                        record(i).value("jam_berangkat").toString(),
                        record(i).value("jam_tiba").toString(),
                        record(i).value("tanggal").toString(),
                        record(i).value("id_bandara_asal").toInt(),
                        record(i).value("id_bandara_tujuan").toInt(),
                        record(i).value("id_pesawat").toInt(),
                        record(i).value("bandara_asal").toString(),
                        record(i).value("bandara_tujuan").toString(),
                        record(i).value("pesawat").toString()
                        );
            retVal.push_back(penerbangan);
        }
    }
    return retVal;
}

QList<Penerbangan> PenerbanganModel::getPenerbanganBy(QString criteria) {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Penerbangan> retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT pnb.id as id, pnb.jam_berangkat as jam_berangkat, pnb.jam_tiba as jam_tiba, "
                                  "pnb.tanggal as tanggal, pnb.id_bandara_asal as id_bandara_asal, pnb.id_bandara_tujuan as id_bandara_tujuan, "
                                  "pnb.id_pesawat as id_pesawat, bdr1.nama as bandara_asal, bdr2.nama as bandara_tujuan, pswt.nama as pesawat "
                           "FROM penerbangan as pnb, bandara as bdr1, bandara as bdr2, pesawat as pswt "
                           "WHERE pnb.id_bandara_asal = bdr1.id AND pnb.id_bandara_tujuan = bdr2.id AND pnb.id_pesawat = pswt.id";
        if (criteria != "") {
            theQuery.append(" AND ");
            theQuery.append(criteria);
        }
        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            Penerbangan penerbangan(
                        record(i).value("id").toInt(),
                        record(i).value("jam_berangkat").toString(),
                        record(i).value("jam_tiba").toString(),
                        record(i).value("tanggal").toString(),
                        record(i).value("id_bandara_asal").toInt(),
                        record(i).value("id_bandara_tujuan").toInt(),
                        record(i).value("id_pesawat").toInt(),
                        record(i).value("bandara_asal").toString(),
                        record(i).value("bandara_tujuan").toString(),
                        record(i).value("pesawat").toString()
                        );
            retVal.push_back(penerbangan);
        }
    }
    return retVal;
}

void PenerbanganModel::createPenerbangan() {
    //-- Penerbangan
    //----- Create SQL Query
    QString pnbQuery = "INSERT INTO penerbangan(jam_berangkat, jam_tiba, tanggal, id_bandara_asal, id_bandara_tujuan,id_pesawat) VALUES (";
    pnbQuery += "\""+jam_berangkat+"\",";
    pnbQuery += "\""+jam_tiba+"\",";
    pnbQuery += "\""+tanggal_berangkat+"\",";
    pnbQuery += QString::number(bandara_berangkat.getID())+",";
    pnbQuery += QString::number(bandara_tiba.getID())+",";
    pnbQuery += QString::number(m_Pesawat.getID());
    pnbQuery += ")";

    //----- Get Database
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");

    //----- Querying database
    QSqlQuery query(db);

    query.exec(pnbQuery);
    int index = query.lastInsertId().toInt();


    //-- Penerbangan_Pegawai
    //----- Create SQL Query
    QString pgwQuery = "INSERT INTO penerbangan_pegawai(id_penerbangan, id_pegawai) VALUES ";

    for (int i = 0; i < m_Aviator.length(); i++) {
        pgwQuery += "(" + QString::number(index) + "," + QString::number(m_Aviator[i].getID()) + ")";
        if (i < m_Aviator.length() - 1) {
            pgwQuery += ", ";
        }
    }

    if (m_Crew.length() > 0)
        pgwQuery += ", ";

    for (int i = 0; i < m_Crew.length(); i++) {
        pgwQuery += "(" + QString::number(index) + "," + QString::number(m_Crew[i].getID()) + ")";
        if (i < m_Crew.length() - 1) {
            pgwQuery += ", ";
        }
    }
    query.exec(pgwQuery);

    //-- Clear cache
    m_Aviator.clear();
    m_Crew.clear();
}

//-- for building
void PenerbanganModel::addJam(QString jam, bool berangkat) {
    if (berangkat)
        jam_berangkat = jam;
    else
        jam_tiba = jam;
}

void PenerbanganModel::addTanggal(QString tanggal) {
    tanggal_berangkat = tanggal;
}

void PenerbanganModel::addBandara(Bandara bandara, bool berangkat) {
    if (berangkat) {
        bandara_berangkat.set(bandara);
    } else {
        bandara_tiba.set(bandara);
    }
}

void PenerbanganModel::addAviator(Pegawai pgw) {
    m_Aviator.append(pgw);
}

void PenerbanganModel::addCrew(Pegawai pgw) {
    m_Crew.append(pgw);
}

void PenerbanganModel::addPesawat(Pesawat psw) {
    m_Pesawat.set(psw);
}

QMap<int, QList<int> > PenerbanganModel::getPenerbanganPegawaiMap() {
    /*
     * return < id_penerbangan, list of id_pegawai on id_penerbangan >
     */
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QMap<int, QList<int> > retVal;
    retVal.clear();

    if (db.isOpen()) {
        QString theQuery = "SELECT id_penerbangan, id_pegawai FROM penerbangan,penerbangan_pegawai "
                           "WHERE penerbangan.id=penerbangan_pegawai.id_penerbangan";
        setQuery(theQuery, db);

        int length = rowCount();
        retVal.clear();

        for (int i=0; i<length; ++i) {
            retVal[record(i).value("id_penerbangan").toInt()].append(record(i).value("id_pegawai").toInt());
        }
    }
    return retVal;
}

//--for parking
int PenerbanganModel::getTarifParkirBandaraById(int id){
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    int result;
    if (db.isOpen()){
        setQuery("SELECT * FROM bandara WHERE id = " + QString::number(id), db);
        if (rowCount() > 0){
            result = record(0).value("biaya").toInt();
        }
    }
    return result;
}

QString PenerbanganModel::getPesawatById(int id){
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QString result;
    if (db.isOpen()){
        setQuery("SELECT * FROM pesawat WHERE id = " + QString::number(id), db);
        if (rowCount() > 0){
            result = record(0).value("nama").toString();
        }
    }
    return result;
}

QString PenerbanganModel::getBandaraById(int id){
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QString result;
    if (db.isOpen()){
        setQuery("SELECT * FROM bandara WHERE id = " + QString::number(id), db);
        if (rowCount() > 0){
            result = record(0).value("kode").toString();
        }
    }
    return result;
}

QList<Penerbangan> PenerbanganModel::getPenerbangan(int day, int month, int year) {
    QSqlDatabase db = QSqlDatabase::database("ErlanggaIS");
    QList<Penerbangan> retVal;
    QString q;
    QTextStream out(stdout);

    if (db.isOpen()){
        q = "SELECT * FROM penerbangan";
        if (year == 0){
            //do nothing
        } else {
            if (month == 0){
                q += " WHERE tanggal LIKE '" + QString::number(year) + "/__/__'";
            } else {
                QString smonth = QString("%1").arg(month, 2, 10, QChar('0')).toUpper();
                if (day == 0){
                    q += " WHERE tanggal LIKE '" + QString::number(year) + "/" + smonth + "/__'";
                } else {
                    QString sday = QString("%1").arg(day, 2, 10, QChar('0')).toUpper();
                    q += " WHERE tanggal = '" + QString::number(year) + "/" + smonth + "/" + sday + "'";
                }
            }
        }
        q += " ORDER BY tanggal ASC, jam_berangkat ASC";
        //out << "query: " + q + "\n";
        setQuery(q, db);
        int length = rowCount();
        //out << "query length: " + QString::number(length) + "\n";
        for(int i=0; i<length; ++i) {
            out << record(i).value("id").toString() + "__";
            out << record(i).value("kode_penerbangan").toString() + "__";
            out << record(i).value("jam_berangkat").toString() + "__";
            out << record(i).value("jam_tiba").toString() + "__";
            out << record(i).value("tanggal").toString() + "__";
            out << record(i).value("bandara_asal_id").toString() + "__";
            out << record(i).value("bandara_tujuan_id").toString() + "__";
            out << record(i).value("pesawat_id").toString() + "__\n";
            Penerbangan pbgn(record(i).value("id").toInt(),
                             record(i).value("jam_berangkat").toString(),
                             record(i).value("jam_tiba").toString(),
                             record(i).value("tanggal").toString(),
                             record(i).value("bandara_asal_id").toInt(),
                             record(i).value("bandara_tujuan_id").toInt(),
                             record(i).value("pesawat_id").toInt(),
                             record(i).value("kode_penerbangan").toString());

            retVal.push_back(pbgn);
        }
    }
    return retVal;
}