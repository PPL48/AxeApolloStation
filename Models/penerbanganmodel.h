#ifndef PENERBANGANMODEL_H
#define PENERBANGANMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/penerbangan.h"

class PenerbanganModel : public QSqlTableModel
{
public:
    PenerbanganModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation
private:
    QList<Penerbangan> m_Values;
    bool               m_Valid;
    QTime              m_CacheValidity;
};

#endif // PENERBANGANMODEL_H
