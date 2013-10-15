#ifndef PENERBANGANMODEL_H
#define PENERBANGANMODEL_H

#include <QtSql>
#include <QList>
#include <QMap>

#include "Includes/penerbangan.h"
#include "Includes/bandara.h"
#include "Includes/pegawai.h"
#include "Includes/pesawat.h"

class PenerbanganModel : public QSqlQueryModel
{
public:
    PenerbanganModel(QObject* parent);

    //-- operation
    QList<Penerbangan>  getAllPenerbangan();
    QList<Penerbangan>  getPenerbanganBy(QString criteria);
    void                createPenerbangan();
    bool                updatePenerbangan(int index, Penerbangan penerbangan);
    bool                refreshList();

    QMap<int, QList<int> >  getPenerbanganPegawaiMap();

    //-- for building
    void                addJam(QString jam, bool berangkat);
    void                addTanggal(QString tanggal);
    void                addBandara(Bandara bandara, bool berangkat);
    void                addAviator(Pegawai pgw);
    void                addCrew(Pegawai pgw);
    void                addPesawat(Pesawat psw);

private:
    QString             jam_berangkat, jam_tiba;
    QString             tanggal_berangkat;
    Bandara             bandara_berangkat, bandara_tiba;
    QList<Pegawai>      m_Aviator;
    QList<Pegawai>      m_Crew;
    Pesawat             m_Pesawat;
};

#endif // PENERBANGANMODEL_H
