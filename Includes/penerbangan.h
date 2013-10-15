#ifndef PENERBANGAN_H
#define PENERBANGAN_H

#include <QString>
#include <QVariant>

class Penerbangan
{
public:
    Penerbangan(qint32  id, QString jam_berangkat, QString jam_tiba, QString tanggal,
        qint32  id_bandara_asal, qint32  id_bandara_tujuan, qint32  id_pesawat,
        QString bandara_asal, QString bandara_tujuan, QString pesawat);

    QVariant toVariant();
    QString  toString();

    int     getID();
    QString getDate();
    QString getAirportDepart();
    QString getAirportArrival();
    QString getPesawat();
	
	//--
	QString getTanggal();
    QString getKode_penerbangan();
    QString getJam_tiba();
    QString getJam_berangkat();
    int getPesawat_id();
    int getBandara_asal_id();
    QVariant toVariant();
    QString  toString();

private:
    qint32  id;
    QString jam_berangkat;
    QString jam_tiba;
    QString tanggal;
    qint32  id_bandara_asal;
    qint32  id_bandara_tujuan;
    qint32  id_pesawat;
	
	//--    
	qint32  bandara_asal_id;
    qint32  bandara_tujuan_id;
    qint32  pesawat_id;
	//--
	
    QString bandara_asal;
    QString bandara_tujuan;
    QString pesawat;
};

#endif // PENERBANGAN_H
