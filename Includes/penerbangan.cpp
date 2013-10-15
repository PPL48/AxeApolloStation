#include "penerbangan.h"

Penerbangan::Penerbangan(){

}

Penerbangan::Penerbangan(qint32 a, QString b, QString c, QString d, qint32 e, qint32  f, qint32 g,
                         QString h, QString i, QString j)
{
    id = a;
    jam_berangkat = b;
    jam_tiba = c;
    tanggal = d;
    id_bandara_asal = e;
    id_bandara_tujuan = f;
    id_pesawat = g;

    bandara_asal = h;
    bandara_tujuan = i;
    pesawat = j;
	
	//--
	bandara_asal_id = e;
    bandara_tujuan_id = f;
    pesawat_id = g;
}


QString Penerbangan::toString() {
    QString str = tanggal+" "+bandara_asal+"("+jam_berangkat+") to "+
            bandara_tujuan+"("+jam_tiba+")";
    return str;
}

int Penerbangan::getID() {
    return id;
}

QString Penerbangan::getDate() {
    return tanggal;
}

QString Penerbangan::getAirportDepart() {
    return bandara_asal;
}

QString Penerbangan::getAirportArrival() {
    return bandara_tujuan;
}

QString Penerbangan::getPesawat() {
    return pesawat;
}

//--
QString Penerbangan::getTanggal(){
    return tanggal;
}
QString Penerbangan::getKode_penerbangan(){
    return kode_penerbangan;
}

QString Penerbangan::getJam_berangkat(){
    return jam_berangkat;
}
QString Penerbangan::getJam_tiba(){
    return jam_tiba;
}
int Penerbangan::getPesawat_id(){
    return pesawat_id;
}
int Penerbangan::getBandara_asal_id(){
    return bandara_asal_id;
}