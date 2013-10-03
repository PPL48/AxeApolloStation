#ifndef PENUMPANGMODEL_H
#define PENUMPANGMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/penumpang.h"

class PenumpangModel : public QSqlTableModel
{
public:
    PenumpangModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation
private:
    QList<Penumpang> m_Values;
    bool             m_Valid;
    QTime            m_CacheValidity;
};

#endif // PENUMPANGMODEL_H
