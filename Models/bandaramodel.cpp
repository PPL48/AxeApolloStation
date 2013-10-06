#include "bandaramodel.h"

BandaraModel::BandaraModel(QObject *parent, QSqlDatabase useDb) : QSqlQueryModel(parent), db(useDb)
{

}
