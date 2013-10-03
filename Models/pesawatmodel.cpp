#include "pesawatmodel.h"

PesawatModel::PesawatModel(QObject *parent) : QSqlTableModel(parent)
{

}

Qt::ItemFlags
PesawatModel::flags (const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

QVariant
PesawatModel::data (const QModelIndex &idx, int role) const {
    //-- Check the role
    if (role != Qt::DisplayRole)
        return QVariant();

    //-- See if our cache is still valid


    //-- fetch the cache
    if (idx.column() == 0 && idx.row() < m_Values.count()) {
        return QVariant();
        //return m_Values.at(idx.row());
    } else
        return QVariant();
}
int
PesawatModel::rowCount (const QModelIndex &parent) const {
    return m_Values.count();
}
