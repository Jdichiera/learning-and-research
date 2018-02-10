#include <stdlib.h>
#include <iostream>

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <cppconn\prepared_statement.h>


//https://docs.microsoft.com/en-us/azure/mysql/connect-cpp


std::string DATABASE = "tcp://127.0.0.1:3306";
std::string USERNAME = "root";
std::string PASSWORD = "deunan0622";

void InitDatabase() {
	sql::Driver *driver;
	sql::Connection *connection;
	sql::Statement *statement;
	sql::PreparedStatement *preparedStatement;

	try {
		driver = get_driver_instance();
		connection = driver->connect(DATABASE, USERNAME, PASSWORD);
	}
	catch (sql::SQLException e){
		std::cout << "Could not connect to database. Error message: " << e.what() << std::endl;
		system("pause");
		exit(1);
	}

	statement = connection->createStatement();
	//statement->execute("DROP TABLE IF EXISTS student");
	statement->execute(
		"create table test.user		"
		"(							"
		"	userid int,				"
		"	username varchar(50),	"
		"	pass varchar(50),		"
		"	firstname varchar(50),	"
		"	lastname varchar(50),	"
		"	email varchar(80)		"
		")							"
	);
	statement->execute(
		"create table test.userrole "
		"(							"
		"	id int, 				"
		"	userid int, 			"
		"	isadmin int				"
		")							"
	);
	statement->execute(
		"create table test.course	"
		"(							"
		"	courseid int, 			"
		"	coursename varchar(50),	"
		"	description varchar(50)," 
		"	isonline int, 			"
		"	credits int				"
		")							"
	);
	statement->execute(
		"create table test.registration "
		"(								"
		"	id int, 					"
		"	userid int, 				"
		"	courseid int				"
		")								"
	);
	statement->execute(
		"create table test.semester "
		"(							"
		"	semesterid int, 		"
		"	semstername varchar(50)	"
		")							"
	);
	statement->execute(
		"create table test.courseoffering "
		"(								  "
		"	id int, 					  "
		"	semesterid int, 			  "
		"	courseid int				  "
		")								  "
	);

	delete connection;
	delete statement;
	delete preparedStatement;
}

void SeedDatabase() {
	sql::Driver *driver;
	sql::Connection *connection;
	sql::Statement *statement;
	sql::PreparedStatement *preparedStatement;

	try {
		driver = get_driver_instance();
		connection = driver->connect(DATABASE, USERNAME, PASSWORD);
	}
	catch (sql::SQLException e) {
		std::cout << "Could not connect to database. Error message: " << e.what() << std::endl;
		system("pause");
		exit(1);
	}
	statement = connection->createStatement();
	statement->execute(
		"insert into test.user (userid, username, pass, firstname, lastname, email)"
		"values"
		"(1, 'student1', 's1p', 's1fn', 's1ln', 's1@email'),"
		"(2, 'student2', 's2p', 's2fn', 's2ln', 's2@email'),"
		"(3, 'student3', 's3p', 's3fn', 's3ln', 's3@email'),"
		"(4, 'student4', 's4p', 's4fn', 's4ln', 's4@email'),"
		"(5, 'student5', 's5p', 's5fn', 's5ln', 's5@email'),"
		"(6, 'faculty1', 'f1p', 'f1fn', 'f1ln', 'f1@email'),"
		"(7, 'faculty2', 'f2p', 'f2fn', 'f2ln', 'f2@email'),"
		"(8, 'faculty3', 'f3p', 'f3fn', 'f3ln', 'f3@email'),"
		"(9, 'faculty4', 'f4p', 'f4fn', 'f4ln', 'f4@email'),"
		"(10, 'faculty5', 'f5p', 'f5fn', 'f5ln', 'f5@email')"
	);
	statement->execute(
		"insert into test.userrole (id, userid, isadmin)"
		"values     "
		"(1, 1, 0), "
		"(2, 2, 0), "
		"(3, 3, 0), "
		"(4, 4, 0), "
		"(5, 5, 0), "
		"(6, 6, 1), "
		"(7, 7, 1), "
		"(8, 8, 1), "
		"(9, 9, 1), "
		"(10, 10, 1)"
	);
	statement->execute(
		"INSERT INTO test.course (courseid, coursename, description, isonline, credits)"
		"VALUES													"
		"(1, 'c1', 'c1 description, F-17-1, not online', 0, 1),	"
		"(2, 'c2', 'c2 description, F-17-1, not online', 0, 1),	"
		"(3, 'c3', 'c3 description, F-17-1, not online', 0, 1),	"
		"(4, 'c4', 'c4 description, F-17-2, not online', 0, 1),	"
		"(5, 'c5', 'c5 description, F-17-2, not online', 0, 1),	"
		"(6, 'c6', 'c6 description, F-17-2,		online', 1, 1),	"
		"(7, 'c7', 'c7 description, W-18-1,		online', 1, 1),	"
		"(8, 'c8', 'c8 description, W-18-1,		online', 1, 1),	"
		"(9, 'c9', 'c9 description, W-18-1,		online', 1, 1),	"
		"(10, 'c10', 'c10 description, W-18-2,  online', 1, 1),	"
		"(11, 'c11', 'c11 description, W-18-2,  online', 1, 1),	"
		"(12, 'c12', 'c12 description, W-18-2,  online', 1, 1),	"
		"(13, 'c13', 'c13 description, S-18-1,  online', 1, 1),	"
		"(14, 'c14', 'c14 description, S-18-1,  online', 1, 1),	"
		"(15, 'c15', 'c15 description, S-18-1,  online', 1, 1)  "
	);
	statement->execute(
		"INSERT INTO test.registration (id, userid, courseid) "
		"VALUES												  "
		"(1, 1, 1),											  "
		"(1, 1, 2),											  "
		"(1, 1, 3),											  "
		"(1, 2, 4),											  "
		"(1, 2, 5),											  "
		"(1, 2, 6),											  "
		"(1, 3, 7),											  "
		"(1, 3, 8),											  "
		"(1, 3, 9),											  "
		"(1, 4, 10),										  "
		"(1, 4, 1),											  "
		"(1, 4, 2),											  "
		"(1, 5, 3),											  "
		"(1, 5, 4),											  "
		"(1, 5, 5)											  "
	);
	statement->execute(
		"INSERT INTO test.semester (id, semesterid, semstername)"
		"VALUES													"
		"(1, 'fall17 semester1'),								"
		"(2, 'fall17 semester2'),								"
		"(3, 'winter18 semester1'),								"
		"(4, 'winter18 semester2'),								"
		"(5, 'spring18 semester1')"
	);
	statement->execute(
		"INSERT INTO test.courseoffering(id, semesterid, courseid)"
		"VALUES													  "
		"(1, 1, 1),												  "
		"(1, 1, 2),												  "
		"(1, 1, 3),												  "
		"(1, 2, 4),												  "
		"(1, 2, 5),												  "
		"(1, 2, 6),												  "
		"(1, 3, 7),												  "
		"(1, 3, 8),												  "
		"(1, 3, 9),												  "
		"(1, 4, 10),											  "
		"(1, 4, 11),											  "
		"(1, 4, 12),											  "
		"(1, 5, 13),											  "
		"(1, 5, 14),											  "
		"(1, 5, 15)												  "
	);

	delete connection;
	delete statement;
	delete preparedStatement;
}

int main(void)
{
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
			/* Create a connection */
			driver = get_driver_instance();
			con = driver->connect("tcp://127.0.0.1:3306", "root", "deunan0622");
			/* Connect to the MySQL test database */
			con->setSchema("test");
			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT id from test");
			while (res->next()) {
				// You can use either numeric offsets...
				std::cout << "id = " << res->getInt(1);
				std::cout << ", label = '" << res->getInt("id") << "'" << std::endl;
			}
			delete res;
			delete stmt;
			delete con;
	}
	catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}

	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;

	//cout << endl;
	//cout << "Let's have MySQL count from 10 to 1..." << endl;

	//try {
	//	sql::Driver *driver;
	//	sql::Connection *con;
	//	sql::Statement *stmt;
	//	sql::ResultSet *res;
	//	sql::PreparedStatement *pstmt;

	//	/* Create a connection */
	//	driver = get_driver_instance();
	//	con = driver->connect("tcp://127.0.0.1:3306", "root", "deunan0622");
	//	/* Connect to the MySQL test database */
	//	con->setSchema("test");

	//	stmt = con->createStatement();
	//	stmt->execute("DROP TABLE IF EXISTS test");
	//	stmt->execute("CREATE TABLE test(id INT)");
	//	delete stmt;

	//	/* '?' is the supported placeholder syntax */
	//	pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
	//	for (int i = 1; i <= 10; i++) {
	//		pstmt->setInt(1, i);
	//		pstmt->executeUpdate();
	//	}
	//	delete pstmt;

	//	/* Select in ascending order */
	//	pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
	//	res = pstmt->executeQuery();

	//	/* Fetch in reverse = descending order! */
	//	res->afterLast();
	//	while (res->previous())
	//		cout << "\t... MySQL counts: " << res->getInt("id") << endl;
	//	delete res;

	//	delete pstmt;
	//	delete con;

	//}
	//catch (sql::SQLException &e) {
	//	cout << "# ERR: SQLException in " << __FILE__;
	//	cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
	//	cout << "# ERR: " << e.what();
	//	cout << " (MySQL error code: " << e.getErrorCode();
	//	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	//}

	//cout << endl;

	//system("pause");
	//return EXIT_SUCCESS;
}