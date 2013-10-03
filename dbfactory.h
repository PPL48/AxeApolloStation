#ifndef DBFACTORY_H
#define DBFACTORY_H

#include <QtSql>

#include "Models/bagasimodel.h"
#include "Models/bandaramodel.h"
#include "Models/pegawaimodel.h"
#include "Models/pemesanmodel.h"
#include "Models/penerbanganmodel.h"
#include "Models/penumpangmodel.h"
#include "Models/pesawatmodel.h"

#include "Models/dbconfig.h"

class DbFactory : public QObject
{
public:
    static DbFactory* createInstance(DbConfig *config);
    static DbFactory* instance();

    static BagasiModel*      getBagasiModel();
    static BandaraModel*     getBandaraModel();
    static PegawaiModel*     getPegawaiModel();
    static PemesanModel*     getPemesanModel();
    static PenerbanganModel* getPenerbanganModel();
    static PenumpangModel*   getPenumpangModel();
    static PesawatModel*     getPesawatModel();

private:
    DbFactory();

    static DbFactory*        _instance;

    static BagasiModel*      m_Bagasi;
    static BandaraModel*     m_Bandara;
    static PegawaiModel*     m_Pegawai;
    static PemesanModel*     m_Pemesan;
    static PenerbanganModel* m_Penerbangan;
    static PenumpangModel*   m_Penumpang;
    static PesawatModel*     m_Pesawat;
};

#endif // DBFACTORY_H
