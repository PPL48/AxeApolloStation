#ifndef PESAWATMODEL_H
#define PESAWATMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pesawat.h"

class PesawatModel : public QSqlTableModel
{
public:
    PesawatModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation
private:
    QList<Pesawat>  m_Values;
    bool            m_Valid;
    QTime           m_CacheValidity;
};

#endif // PESAWATMODEL_H
