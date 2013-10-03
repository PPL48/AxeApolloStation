#ifndef BANDARAMODEL_H
#define BANDARAMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/bandara.h"

class BandaraModel : public QSqlTableModel
{
public:
    BandaraModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation

private:
    QList<Bandara>  m_Values;
    bool            m_Valid;
    QTime           m_CacheValidity;
};

#endif // BANDARAMODEL_H
