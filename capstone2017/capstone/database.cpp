#include "database.h"
#include <QDebug>
#include <QTextEdit>

Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
}

bool Database::AdminLogin(const QString &username, const QString &password){
    m_db.setDatabaseName("college");
    m_db.setHostName("127.0.0.1");
    m_db.setPort(3306);
    m_db.setUserName(username);
    m_db.setPassword(password);

    if(!m_db.open()){
        qInfo() << "Error: Database connection failed!" << m_db.hostName();
        qInfo() << m_db.lastError() << username << " : " << password;
        return false;
    }
    else {
       return true;
    }
}

void Database::OpenConnection(){

    // qInfo() << "Attempting database connection ...";
    m_db.setDatabaseName("college");
    m_db.setHostName("127.0.0.1");
    m_db.setPort(3306);
    m_db.setUserName("root");
    m_db.setPassword("password");
    //QStringList tables = m_db.tables();
    if(!m_db.open()){
        qInfo() << "Error: Database connection failed!" << m_db.hostName();
        qInfo() << m_db.lastError();
    }
    else {
       qInfo() << "Database: connection OK!" << m_db.hostName();
    }
}

void Database::CloseConnection()
{
    qInfo() << "Close connection";
    m_db.close();
}

void Database::DropTables()
{
    OpenConnection();
    //QString dropTableStudent = "DROP TABLE IF EXISTS college.student";
    //QString dropTableFaculty = "DROP TABLE IF EXISTS college.faculty";
    QString dropTableUser = "DROP TABLE IF EXISTS college.user";
    QString dropTableRegistration = "DROP TABLE IF EXISTS college.registration";
    QString dropTableCourse = "DROP TABLE IF EXISTS college.course";
    QString dropTableCourseOffering = "DROP TABLE IF EXISTS college.courseoffering";
    QString dropTableSemester = "DROP TABLE IF EXISTS college.semester";

    qInfo() <<  "Drop user table";
    ExecuteQuery(dropTableUser);
    qInfo() <<  "Drop registration table";
    ExecuteQuery(dropTableRegistration);
    qInfo() <<  "Drop course table";
    ExecuteQuery(dropTableCourse);
    qInfo() <<  "Drop course offering table";
    ExecuteQuery(dropTableCourseOffering);
    qInfo() <<  "Drop semester table";
    ExecuteQuery(dropTableSemester);
    CloseConnection();
}

void Database::CreateTables(){
   OpenConnection();
    QString createTableUser = "CREATE TABLE college.user "
                                  "(id int,"
                                  "username varchar(50), "
                                  "password varchar(50),"
                                  "firstname varchar(50),"
                                  "lastname varchar(50),"
                                  "email varchar(50),"
                                  "isadmin int )";
    QString createTableRegistration = "CREATE TABLE college.registration "
                                      "(id int,"
                                      "studentid int,"
                                      "courseid int,"
                                      "status varchar(1),"
                                      "grade double,"
                                      "registration date,"
                                      "completion date )";
    QString createTableCourse = "CREATE TABLE college.course "
                                "(id int,"
                                "name varchar(50),"
                                "description varchar(50),"
                                "credits int,"
                                "type varchar(1),"
                                "active int,"
                                "semester int )";
    QString createTableCourseOffering = "CREATE TABLE college.courseoffering "
                                        "(id int,"
                                        "semesterid int,"
                                        "courseid int )";
    QString createTableSemester = "CREATE TABLE college.semester "
                                  "(id int,"
                                  "name varchar(50) )";
    qInfo() <<  "Create user table";
    ExecuteQuery(createTableUser);
    qInfo() <<  "Create registration table";
    ExecuteQuery(createTableRegistration);
    qInfo() <<  "Create course table";
    ExecuteQuery(createTableCourse);
    qInfo() <<  "Create course offering table";
    ExecuteQuery(createTableCourseOffering);
    qInfo() <<  "Create semester table";
    ExecuteQuery(createTableSemester);
    CloseConnection();
}

void Database::SeedDatabase()
{
    OpenConnection();
    QString seedTableUser = "INSERT INTO college.user "
                            "(id, username, password, firstname, lastname, email, isadmin)"
                            "VALUES"
                            "(1, 'student1', 's1p', 's1fn', 's1ln', 's1@email', 0),"
                            "(2, 'student2', 's2p', 's2fn', 's2ln', 's2@email', 0),"
                            "(3, 'student3', 's3p', 's3fn', 's3ln', 's3@email', 0),"
                            "(4, 'faculty1', 'f1p', 'f1fn', 'f1ln', 'f1@email', 1),"
                            "(5, 'faculty2', 'f2p', 'f2fn', 'f2ln', 'f2@email', 1) ";
    QString seedTableRegistration = "INSERT INTO college.registration "
                                    "(id, studentid, courseid, status, grade, registration, completion)"
                                    "VALUES"
                                    // Student 1 in progress courses
                                    "(1, 1, 1, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    "(2, 1, 2, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 1 Passed courses
                                    "(3, 1, 31, 'p', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 1 failed courses
                                    "(4, 1, 32, 'f', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 1 dropped courses
                                    "(5, 1, 33, 'd', 4.00, '2017-1-04', '2017-4-04'),  "

                                    // Student 2 in progress courses
                                    "(6, 2, 3, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    "(7, 2, 4, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 2 Passed courses
                                    "(8, 2, 34, 'p', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 2 failed courses
                                    "(9, 2, 35, 'f', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 2 dropped courses
                                    "(10, 2, 36, 'd', 4.00, '2017-1-04', '2017-4-04'),  "

                                    // Student 3 in progress courses
                                    "(11, 3, 5, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    "(12, 3, 6, 'i', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 3 Passed courses
                                    "(13, 3, 37, 'p', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 3 failed courses
                                    "(14, 3, 38, 'f', 4.00, '2017-1-04', '2017-4-04'),  "
                                    // Student 3 dropped courses
                                    "(15, 3, 39, 'd', 4.00, '2017-1-04', '2017-4-04')  ";
    QString seedTableCourse = "INSERT INTO college.course "
                              "(id, name, description, credits, type, active, semester)"
                              "VALUES"
                              // Currently registered courses for students
                              "(1,  'Course Student 1 T',  'A traditional course for student 1', 3, 't', 1, 1),	"
                              "(2,  'Course Student 1 O',  'An Online course for student 1', 3, 'o', 1, 2),	"
                              "(3,  'Course Student 2 T',  'A traditional course for student 2', 3, 't', 1, 1),	"
                              "(4,  'Course Student 2 O',  'An Online course for student 2', 3, 'o', 1, 2),	"
                              "(5,  'Course Student 3 T',  'A traditional course for student 3', 3, 't', 1, 1),	"
                              "(6,  'Course Student 3 O',  'An Online course for student 3', 3, 'o', 1, 2),	"

                              // Closed courses will show up for faculty but not for students
                              "(17,  'Course CLOSED T',  'A traditional course that is closed', 3, 't', 0, 3),	"
                              "(18,  'Course CLOSED O',  'An Online course that is closed', 3, 'o', 0, 3),	"

                              // Open courses that students can register for
                              "(27,  'Course OPEN T',  'A traditional course that is closed', 3, 't', 1, 4),	"
                              "(28,  'Course OPEN O',  'An Online course that is closed', 3, 'o', 1, 4),	"

                              // Courses for students with different completion statuses
                              "(31,  'Passed Course Student 1 T',  'A passed traditional course for student 1', 3, 't', 1, 5),	"
                              "(32,  'Failed Course Student 1 O',  'An failed Online course for student 1', 3, 'o', 1, 6),	"
                              "(33,  'Dropped Course Student 1 O',  'An dropped Online course for student 1', 3, 'o', 1, 6),	"

                              "(34,  'Passed Course Student 2 T',  'A passed traditional course for student 1', 3, 't', 1, 5),	"
                              "(35,  'Failed Course Student 2 O',  'An failed Online course for student 1', 3, 'o', 1, 6),	"
                              "(36,  'Dropped Course Student 2 O',  'An dropped Online course for student 1', 3, 'o', 1, 6),	"

                              "(37,  'Passed Course Student 3 T',  'A passed traditional course for student 1', 3, 't', 1, 5),	"
                              "(38,  'Failed Course Student 3 O',  'An failed Online course for student 1', 3, 'o', 1, 6),	"
                              "(39,  'Dropped Course Student 3 O',  'An dropped Online course for student 1', 3, 'o', 1, 6)	";


    QString seedTableCourseOffering = "INSERT INTO college.courseoffering "
                                      "(id, semesterid,courseid)"
                                      "VALUES"
                                      "(1,  1, 1 ),"
                                      "(2,  1, 2 ),"
                                      "(3,  1, 3 ),"
                                      "(4,  2, 4 ),"
                                      "(5,  2, 5 ),"
                                      "(6,  2, 6 ),"
                                      "(7,  3, 7 ),"
                                      "(8,  3, 8 ),"
                                      "(9,  3, 9 ),"
                                      "(10, 4, 10),"
                                      "(11, 4, 11),"
                                      "(12, 4, 12),"
                                      "(13, 5, 13),"
                                      "(14, 5, 14),"
                                      "(15, 5, 15)";
    QString seedTableSemester = "INSERT INTO college.semester "
                                "(id, name)"
                                "VALUES"
                                "(1, 'fall17   semester1'),"
                                "(2, 'fall17   semester2'),"
                                "(3, 'winter18 semester1'),"
                                "(4, 'winter18 semester2'),"
                                "(5, 'spring18 semester1'),"
                                "(6, 'spring18 semester2') ";
    qInfo() <<  "Seed user table";
    ExecuteQuery(seedTableUser);
    qInfo() <<  "Seed registration table";
    ExecuteQuery(seedTableRegistration);
    qInfo() <<  "Seed course table";
    ExecuteQuery(seedTableCourse);
    qInfo() <<  "Seed course offering table";
    ExecuteQuery(seedTableCourseOffering);
    qInfo() <<  "Seed semester table";
    ExecuteQuery(seedTableSemester);
    CloseConnection();
}

void Database::ExecuteQuery(const QString queryString){
    QSqlQuery query;
    if(query.exec(queryString)){
        qInfo() <<  "++Success!";
    }
    else{
        qInfo() <<  query.lastError();
    }

}

//QSqlQuery Database::ExecuteQueryWithReturn(const QString queryString){
//    QSqlQuery query;
//    return query.exec(queryString);
//}

bool Database::CheckCredentials(const QString _username, QString _password){
    qInfo() << "Check Credentials";
    bool credentialsValid = false;
    QSqlQuery query;
    QString queryUsernameString = "SELECT username FROM college.user WHERE username = '" + _username + "'";
    QString queryPasswordString = "SELECT password FROM college.user WHERE username = '" + _username + "'";
    query.exec(queryUsernameString);
    query.first();
    qInfo() << "Check username";
    if(_username == query.value(0).toString()){
        qInfo() << "Check password";
        query.exec(queryPasswordString);
        query.first();
        if(_password == query.value(0).toString()){
            credentialsValid = true;
        }
    }

    return credentialsValid;
}
bool Database::CheckUsername(const QString _username)
{
    qInfo() << "Check Username";
    bool usernameValid = false;
    QSqlQuery query;
    QString queryString = "SELECT username FROM college.user WHERE username = '" + _username + "'";
    query.exec(queryString);
    query.first();
    if(_username == query.value(0).toString()){
        usernameValid = true;
    }

    return usernameValid;
}

bool Database::CheckPassword(const QString _password)
{
    qInfo() << "Check Password";
    bool passwordValid = false;
    QSqlQuery query;
    QString queryString = "SELECT password FROM college.user WHERE username = '" + _password + "'";
    query.exec(queryString);
    query.first();
    if(_password == query.value(0).toString()){
        passwordValid = true;
    }
    qInfo() <<  query.lastError();
    return passwordValid;
}

bool Database::CheckAdmin(const QString _username)
{
    qInfo() << "Check Admin";
    bool isAdmin = false;
    QSqlQuery query;
    QString queryString = "SELECT isadmin FROM college.user WHERE username = '" + _username + "'";
    query.exec(queryString);
    query.first();
    if(query.value(0).toInt() == 1){
        isAdmin = true;
    }
    return isAdmin;

}

