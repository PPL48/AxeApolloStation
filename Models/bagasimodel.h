#ifndef BAGASIMODEL_H
#define BAGASIMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/bagasi.h"

class BagasiModel : public QSqlTableModel
{
public:
    BagasiModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation
    bool insertBagasi();
    bool updateBagasi();

private:
    QList<Bagasi>   m_Values;
    bool            m_Valid;
    QTime           m_CacheValidity;
};

#endif // BAGASIMODEL_H
