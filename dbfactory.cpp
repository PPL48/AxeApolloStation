#include "dbfactory.h"

#include <QMessageBox>

BagasiModel*      DbFactory::m_Bagasi  = NULL;
BandaraModel*     DbFactory::m_Bandara = NULL;
PegawaiModel*     DbFactory::m_Pegawai = NULL;
PemesanModel*     DbFactory::m_Pemesan = NULL;
PemesananModel*   DbFactory::m_Pemesanan = NULL;
PenerbanganModel* DbFactory::m_Penerbangan = NULL;
PenumpangModel*   DbFactory::m_Penumpang = NULL;
PesawatModel*     DbFactory::m_Pesawat  = NULL;

DbFactory*        DbFactory::_instance = NULL;

DbConfig*         DbFactory::m_Config;

DbFactory::DbFactory( )
{
}

DbFactory* DbFactory::createInstance(const DbConfig &config) {
    if (!_instance) {
        _instance = new DbFactory;
        m_Config  = new DbConfig(config);

        QSqlDatabase login = QSqlDatabase::addDatabase("QMYSQL", "SysLogin");
        login.setHostName(m_Config->getHost());
        login.setUserName(m_Config->getUser());
        login.setPassword(m_Config->getPass());
        if (!login.open())
            QMessageBox::critical(0, "Database error", "Credentials not load");

        QSqlDatabase erlangga = QSqlDatabase::addDatabase("QMYSQL", "ErlanggaIS");
        erlangga.setHostName(m_Config->getHost());
        erlangga.setUserName(m_Config->getUser());
        erlangga.setPassword(m_Config->getPass());
        erlangga.setDatabaseName(m_Config->getDbName());

        if (!erlangga.open())
            QMessageBox::critical(0, "Database error", "Cannot load database");
    }
    return _instance;
}

DbFactory* DbFactory::instance() {
    return _instance;
}

BagasiModel*      DbFactory::getBagasiModel() {
    if (!m_Bagasi) {
        m_Bagasi = new BagasiModel(_instance, QSqlDatabase::database("ErlanggaIS"));
    }
    return m_Bagasi;
}

BandaraModel*     DbFactory::getBandaraModel() {
    if (!m_Bandara) {
        m_Bandara = new BandaraModel(_instance, QSqlDatabase::database("ErlanggaIS"));
    }
    return m_Bandara;
}

PegawaiModel*     DbFactory::getPegawaiModel() {
    if (!m_Pegawai) {
        m_Pegawai = new PegawaiModel(_instance);
    }
    return m_Pegawai;
}

PemesanModel*     DbFactory::getPemesanModel() {
    if (!m_Pemesan) {
        m_Pemesan = new PemesanModel(_instance);
    }
    return m_Pemesan;
}

PemesananModel*   DbFactory::getPemesananModel() {
    if (!m_Pemesanan) {
        m_Pemesanan = new PemesananModel(_instance);
    }
    return m_Pemesanan;
}

PenerbanganModel* DbFactory::getPenerbanganModel() {
    if (!m_Penerbangan) {
        m_Penerbangan = new PenerbanganModel(_instance);
    }
    return m_Penerbangan;
}

PenumpangModel*   DbFactory::getPenumpangModel() {
    if (!m_Penumpang) {
        m_Penumpang = new PenumpangModel(_instance);
    }
    return m_Penumpang;
}

PesawatModel*     DbFactory::getPesawatModel() {
    if (!m_Pesawat) {
        m_Pesawat = new PesawatModel(_instance);
    }
    return m_Pesawat;
}

