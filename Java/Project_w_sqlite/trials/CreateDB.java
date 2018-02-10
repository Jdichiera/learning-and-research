//Connects to a local DB and creates the tables

import java.sql.*;

public class CreateDB{
    public static void main(String args[]){
        //createStocksTable();
        hydrateTable();
    }

    public static void createStocksTable(){
        Connection c = null;
        Statement stmt = null;

        try{
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:stocks.db");
            System.out.println("Opened database successfully");

            stmt = c.createStatement();

            String sql = "CREATE TABLE STOCKS " +
                    "(SYMBOL PRIMARY KEY NOT NULL," +
                    "NAME TEXT NOT NULL)";
            stmt.executeUpdate(sql);
            stmt.close();
            c.close();
        }catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Stocks table created successfully.");
    }

    public static void createUserStocksTable(){
        Connection c = null;
        Statement stmt = null;

        try{
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:userstocks.db");
            System.out.println("Opened database successfully");

            stmt = c.createStatement();

            String sql = "CREATE TABLE USERSTOCKS " +
                    "(USERID PRIMARY KEY NOT NULL," +
                    "SYMBOL TEXT NOT NULL)";
            stmt.executeUpdate(sql);
            stmt.close();
            c.close();
        }catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Stocks table created successfully.");
    }

    public static void hydrateTable(){
        Connection c = null;
        Statement stmt = null;

        try{
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:stocks.db");
            c.setAutoCommit(false);
            System.out.print("Opened database successfully");

            stmt = c.createStatement();
            String sql = "INSERT INTO STOCKS(SYMBOL, NAME)" +
                        "VALUES('AAA','AAA Company Stock');";
            stmt.executeUpdate(sql);

            stmt.close();
            c.commit();
            c.close();
        }catch(Exception e){
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Records created successfully");
    }
}