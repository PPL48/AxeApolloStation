#include "dbconfig.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

DbConfig::DbConfig()
{
    m_Hostname = "167.205.34.202";
    m_Username = "root";
    m_Password = "";
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
