#ifndef DBCONFIG_H
#define DBCONFIG_H

#include <QFile>
#include <QSqlDatabase>

class DbConfig
{
public:
    DbConfig(QString hostname, QString username, QString password, QString dbname);
    DbConfig(const DbConfig& config);

    QString getHost();
    QString getUser();
    QString getPass();
    QString getDbName();
private:
    QString m_Hostname;
    QString m_Username;
    QString m_Password;
    QString m_DbName;
};

#endif // DBCONFIG_H
