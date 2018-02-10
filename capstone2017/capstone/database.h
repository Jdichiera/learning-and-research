#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();
    void OpenConnection();
    void CloseConnection();
    bool AdminLogin(const QString &username, const QString &password);
    void DropTables();
    void CreateTables();
    void SeedDatabase();
    void ExecuteQuery(const QString queryString);
    QSqlQuery ExecuteQueryWithReturn(const QString queryString);
    bool CheckUsername(const QString _username);
    bool CheckPassword(const QString _password);
    bool CheckCredentials(QString _username, QString _password);
    bool CheckAdmin(const QString _username);
    //QSqlQuery *query;
private:
    QSqlDatabase m_db;


};

#endif // DATABASE_H
