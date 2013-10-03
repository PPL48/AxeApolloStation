#include "dbfactory.h"

BagasiModel*      DbFactory::m_Bagasi  = NULL;
BandaraModel*     DbFactory::m_Bandara = NULL;
PegawaiModel*     DbFactory::m_Pegawai = NULL;
PemesanModel*     DbFactory::m_Pemesan = NULL;
PenerbanganModel* DbFactory::m_Penerbangan = NULL;
PenumpangModel*   DbFactory::m_Penumpang = NULL;
PesawatModel*     DbFactory::m_Pesawat  = NULL;

DbFactory*        _instance = NULL;

DbFactory::DbFactory()
{

}

DbFactory* DbFactory::createInstance(DbConfig *config) {
    if (!_instance)
        _instance = new DbFactory;
}

DbFactory* DbFactory::instance() {
    return _instance;
}

BagasiModel*      DbFactory::getBagasiModel() {
    if (!m_Bagasi) {
        m_Bagasi = new BagasiModel(this);
    }
}

BandaraModel*     DbFactory::getBandaraModel() {

}

PegawaiModel*     DbFactory::getPegawaiModel() {

}

PemesanModel*     DbFactory::getPemesanModel() {

}

PenerbanganModel* DbFactory::getPenerbanganModel() {

}

PenumpangModel*   DbFactory::getPenumpangModel() {

}

PesawatModel*     DbFactory::getPesawatModel() {

}

