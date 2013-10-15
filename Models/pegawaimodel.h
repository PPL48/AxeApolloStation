#ifndef PEGAWAIMODEL_H
#define PEGAWAIMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pegawai.h"

class PegawaiModel : public QSqlQueryModel
{
public:
    PegawaiModel(QObject* parent);

    //-- operation
    QList<Pegawai>  getAllPegawai();
    QList<Pegawai>  getPegawaiBy(QString criteria);
    bool            insertPegawai(Pegawai pegawai);
    bool            updatePegawai(int index, Pegawai pegawai);
    bool            refreshList();

    QMap<int, Pegawai> getAviatorMappedID();
    QMap<int, Pegawai> getCrewMappedID();
};

#endif // PEGAWAIMODEL_H
