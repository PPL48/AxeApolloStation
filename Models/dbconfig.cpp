#include "dbconfig.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

DbConfig::DbConfig(QString hostname, QString username,
                   QString password, QString dbname)
{
    m_Hostname = hostname;
    m_Username = username;
    m_Password = password;
    m_DbName   = dbname;
}

DbConfig::DbConfig(const DbConfig& config) {
    m_Hostname = config.m_Hostname;
    m_Username = config.m_Username;
    m_Password = config.m_Password;
    m_DbName   = config.m_DbName;
}

QString DbConfig::getHost() {
    return m_Hostname;
}

QString DbConfig::getUser() {
    return m_Username;
}

QString DbConfig::getPass() {
    return m_Password;
}

QString DbConfig::getDbName() {
    return m_DbName;
}
