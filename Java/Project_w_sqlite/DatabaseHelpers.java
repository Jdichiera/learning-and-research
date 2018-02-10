package Java.Project_w_sqlite;
/**
 * build : javac -classpath jdbc.jar
 * run : java -classpath ".:jdbc.jar"
 *
 */

import java.sql.*;

public class DatabaseHelpers{

    public static Connection getConnection(){
        //System.out.println("\n\n\t--++ Connect to DB ++--");
        //System.out.println("Attempting connection ... ");

        Connection connection = null;

        String databasePath = "jdbc:sqlite:test.db";
        String driverPath = "org.sqlite.JDBC";

        try {
            Class.forName(driverPath);
            connection = DriverManager.getConnection(databasePath);
            //System.out.println("++++ Database connection successful.");
        } catch (Exception e) {
            System.out.println("--!! Could not connect to the database ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
        }

        return connection;
    }

    public static void closeObjects(Connection connectionObject, Statement
            statementObject){
        //System.out.println("\n\n\t--++ Close Result Statement and Connection " +
                //"Object ++--");
        //System.out.println("Attempting to close objcts... ");
        try {

            if (statementObject != null) {
                statementObject.close();
                //System.out.println("++++ Statement object closed.");
            }


            if (connectionObject != null) {
                connectionObject.close();
                //System.out.println("++++ Connection object closed.");
            }
        }

         catch (Exception e) {
            System.out.println("--!! Could not close objects ... \n");
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }
    }


    public static void executeUpdate(String update){

        //System.out.println("\n\n\t--++ Execute Update ++--");
        System.out.println("\n ==== Attempting to execute update ==== \n " +
                update + "\n ====");
        Statement statement = null;


        try {
            Connection connection = getConnection();

            connection.setAutoCommit(false);

            statement = connection.createStatement();

            statement.executeUpdate(update);

            connection.commit();

            closeObjects(connection, statement);

            //System.out.println("++++ Update statement executed successfully.");
        } catch (Exception e) {
            System.out.println("--!! Could not execute statement ... \n");
            System.out.println(update);
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
        }

    }

    public static ResultSet executeQuery(String query){
        //System.out.println("\n\n\t--++ Execute Query ++--");
        System.out.println("\n ==== Attempting to execute query ==== \n " +
                query + "\n ====");

        Statement statement = null;
        ResultSet results = null;


        try {
            Connection connection = getConnection();

            connection.setAutoCommit(false);

            statement = connection.createStatement();

            results = statement.executeQuery(query);

            //System.out.println("++++ Query executed successfully.");

            results.close();

            closeObjects(connection, statement);

        } catch (Exception e) {
            System.out.println("--!! Could not execute query ... \n");
            System.out.println(statement);
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
        }
        return results;
    }

    public static void printQuery(String query){
        Statement statement = null;
        ResultSet results = null;


        try {
            Connection connection = getConnection();

            connection.setAutoCommit(false);

            statement = connection.createStatement();

            results = statement.executeQuery(query);

            ResultSetMetaData resultsMeta = results.getMetaData();

            int numColumns = resultsMeta.getColumnCount();

            //System.out.println("++++ Query executed successfully.");

            //System.out.println("\t\t\n--== Stocks Database ==--");
            while (results.next()){
                for (int i = 1; i < numColumns; i++){
                    System.out.print("\t" + resultsMeta.getColumnLabel(i) +
                            " : " + results.getString(i));
                }
                System.out.printf("\n");
            }

            results.close();

            closeObjects(connection, statement);

        } catch (Exception e) {
            System.out.println("--!! Could not execute query ... \n");
            System.out.println(statement);
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
        }
    }

    public static User getUser(int userId){
        Statement statement = null;
        ResultSet results = null;

        String query = "SELECT * FROM Users WHERE ID = " + userId;

        try {
            Connection connection = getConnection();

            connection.setAutoCommit(false);

            statement = connection.createStatement();

            results = statement.executeQuery(query);

            //System.out.println("++++ Query executed successfully.");
            int id = results.getInt(1);
            String fName = results.getString(2);
            String lName = results.getString(3);
            String pass = results.getString(4);
            int admn = results.getInt(5);
            User user = new User(id, fName, lName, pass, admn);
            results.close();

            closeObjects(connection, statement);

        } catch (Exception e) {
            System.out.println("--!! Could not execute query ... \n");
            System.out.println(statement);
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
        }
        return user;
    }

}