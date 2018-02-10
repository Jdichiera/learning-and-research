#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();
private:
    QSqlDatabase m_db;
    void InitializeDatabase();
};

#endif // DATABASE_H
