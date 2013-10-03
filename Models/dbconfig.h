#ifndef DBCONFIG_H
#define DBCONFIG_H

#include <QFile>
#include <QSqlDatabase>

class DbConfig : public QSqlDatabase
{
public:
    DbConfig();

    QString getHost();
    QString getUser();
    QString getPass();
private:
    QString m_Hostname;
    QString m_Username;
    QString m_Password;
};

#endif // DBCONFIG_H
