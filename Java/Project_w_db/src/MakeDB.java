/**
 * Created by udichje on 5/7/17.
 */

import java.sql.*;
import java.io.*;

public class MakeDB {
    public static void MakeDB() throws Exception{
        Class.forName("org.sqlite.JDBC");
        String databasePath = "jdbc:sqlite:StockDatabase.db";

        Connection connection = DriverManager.getConnection(databasePath);
        Statement statement = connection.createStatement();

        System.out.println("Dropping indexes & tables ... ");

        try
        {
            statement.executeUpdate("DROP INDEX PK_UserStocks ON UserStocks");
        }
        catch (Exception e)
        {
            System.out.println("Could not drop PK on UserStocks table: "
                    + e.getMessage());
        }


        try
        {
            statement.executeUpdate("DROP TABLE UserStocks");
        }
        catch (Exception e)
        {
            System.out.println("Could not drop UserStocks table: "
                    + e.getMessage());
        }


        try
        {
            statement.executeUpdate("DROP TABLE Users");
        }
        catch (Exception e)
        {
            System.out.println("Could not drop Users table: "
                    + e.getMessage());
        }


        try
        {
            statement.executeUpdate("DROP TABLE Stocks");
        }
        catch (Exception e)
        {
            System.out.println("Could not drop Stocks table: "
                    + e.getMessage());
        }


        System.out.println("Creating tables ... ");


        try
        {
            String update = "CREATE TABLE Stocks (symbol TEXT(8) NOT NULL " +
                    "CONSTRAINT PK_Stocks PRIMARY KEY, name TEXT(50))";
            System.out.println("Creating Stocks table with PK index ... ");
            statement.executeUpdate(update);
        }
        catch (Exception e)
        {
            System.out.println("Could not CREATE Stocks table: "
                    + e.getMessage());
        }


        try
        {
            String update = "CREATE TABLE Users (userID TEXT(20) NOT NULL " +
                    "CONSTRAINT PK_Users PRIMARY KEY, firstName TEXT(30) NOT " +
                    "NULL, lastName TEXT(30) NOT NULL, password INT NOT NULL," +
                    " admin INT NOT NULL)";
            System.out.println("Creating Users table with PK index ... ");
            statement.executeUpdate(update);
        }
        catch (Exception e)
        {
            System.out.println("Could not create Users table: "
                    + e.getMessage());
        }


        try
        {
            String update = "CREATE TABLE UserStocks (userID TEXT(20) " +
                    "CONSTRAINT FK1_UserStocks REFERENCES Users (userID), " +
                    "symbol TEXT(8), CONSTRAINT FK2_UserStocks FOREIGN KEY " +
                    "(symbol) REFERENCES Stocks (symbol))";
            System.out.println("Creating UserStocks table ... ");
            statement.executeUpdate(update);
        }
        catch (Exception e)
        {
            System.out.println("Could not create UserStocks table: "
                    + e.getMessage());
        }


        try
        {
            String update = "CREATE UNIQUE INDEX PK_UserStocks ON UserStocks " +
                    "(userID, symbol)";
            System.out.println("Creating UserStocks table PK index ... ");
            statement.executeUpdate(update);
        }
        catch (Exception e)
        {
            System.out.println("Could not create UserStocks index: "
                    + e.getMessage());
        }


        //Create initial admin user
        String userID = "admin1";
        String firstName = "adminFirst1";
        String lastName = "adminLast1";
        String password = "admin1";
        int admin = 1;

        PreparedStatement pStatement = connection.prepareStatement("INSERT "
                + "INTO Users VALUES (?, ?, ?, ?, ?)");

        try
        {
            pStatement.setString(1, userID);
            pStatement.setString(2, firstName);
            pStatement.setString(3, lastName);
            pStatement.setString(4, password);
            pStatement.setInt(5, admin);
            pStatement.executeUpdate();

        }
        catch (Exception e)
        {
            System.out.println("Exception inserting user: "
                                + e.getMessage());
        }

        pStatement.close();

        //Read and display all User data in the database
        ResultSet results = statement.executeQuery("SELECT * FROM Users");

        System.out.println("Displaying data from DB ...\n");

        while(results.next()){
            System.out.println("ID " + results.getString("UserID"));
            System.out.println("FN " + results.getString("firstName"));
            System.out.println("LN " + results.getString("lastName"));
            System.out.println("PW " + results.getString("password"));
            System.out.println("ADM " + results.getInt("admin"));
        }



    }
}
