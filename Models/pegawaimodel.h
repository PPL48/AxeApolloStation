#ifndef PEGAWAIMODEL_H
#define PEGAWAIMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pegawai.h"

class PegawaiModel : public QSqlTableModel
{
public:
    PegawaiModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation

private:
    QList<Pegawai>  m_Values;
    bool            m_Valid;
    QTime           m_CacheValidity;
};

#endif // PEGAWAIMODEL_H
