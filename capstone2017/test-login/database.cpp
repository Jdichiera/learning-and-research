#include "database.h"
#include <QDebug>
Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setDatabaseName("test");
    m_db.setHostName("127.0.0.1");
    m_db.setPort(3306);
    m_db.setUserName("root");
    m_db.setPassword("jamjam11");
    //QStringList tables = m_db.tables();
    if(!m_db.open()){
        qInfo() << "Error: Database connection failed!" << m_db.hostName();
        qInfo() << m_db.lastError();
    }
    else {
       qInfo() << "Database: connection OK!" << m_db.hostName();
//       for(int i =0; i< tables.size(); i++) {
//           qInfo() << tables.at(i);
//       }
       //QSqlQueryModel *model = new QSqlQueryModel;
       //model->setQuery("SELECT * from test.user");
       QSqlTableModel model;
       model.setTable("user");
       model.select();
       QString name = model.record(4).value("username").toString();
       qInfo() << name;
    }
}

void Database::InitializeDatabase()
{

}
