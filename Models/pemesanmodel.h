#ifndef PEMESANMODEL_H
#define PEMESANMODEL_H

#include <QtSql>
#include <QList>

#include "Includes/pemesan.h"

class PemesanModel : public QSqlTableModel
{
public:
    PemesanModel(QObject* parent);

    Qt::ItemFlags flags (const QModelIndex &index) const;
    QVariant data (const QModelIndex &idx, int role = Qt::DisplayRole) const;
    int rowCount (const QModelIndex &parent = QModelIndex()) const;

    //-- operation
private:
    QList<Pemesan>  m_Values;
    bool            m_Valid;
    QTime           m_CacheValidity;
};

#endif // PEMESANMODEL_H
