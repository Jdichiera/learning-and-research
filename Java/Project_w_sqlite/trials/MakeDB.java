import java.sql.*;
import java.io.*;

public class MakeDB
{
    public static void main(String args[]) throws Exception
    {
        Class.forName("org.sqlite.JDBC");

        String url = "jdbc:sqlite:StockTracker";

        Connection c = DriverManager.getConnection(url);
        Statement stmt = c.createStatement();

        //Delete index and table if they exist. If !exist then display message
        System.out.println("Dropping indexes and tables ... ");

        try
        {
            stmt.executeUpdate("DROP INDEX PK_UserStocks"); //ON UserStocks
        }
        catch(Exception e)
        {
            System.out.println("Could not drop primary key on UserStocks " +
                    "table: " + e.getMessage());
        }

        try
        {
            stmt.executeUpdate("DROP TABLE UserStocks");
        }
        catch(Exception e)
        {
            System.out.println("Could not drop UserStocks table: "
                    + e.getMessage());
        }

        try
        {
            stmt.executeUpdate("DROP TABLE Users");
        }
        catch(Exception e)
        {
            System.out.println("Could not drop Users table: " + e.getMessage());
        }

        try
        {
            stmt.executeUpdate("DROP TABLE Stocks");
        }
        catch(Exception e)
        {
            System.out.println("Could not drop Stocks table: " + e.getMessage());
        }

        //Create DB Tables
        System.out.println("\nCreating tables ... ");

        //Create Stocks table with primary key index
        try
        {
            System.out.println("Creating Stocks table with PK index ... ");
            stmt.executeUpdate("CREATE TABLE Stocks (" +
                                "symbol TEXT(8) NOT NULL " +
                                "CONSTRAINT PK_Stocks PRIMARY KEY, " +
                                "name TEXT(50)" +
                                ")");
        }
        catch(Exception e)
        {
            System.out.println("Exception creating Stocks table: "
                    + e.getMessage());
        }

        //Create Users table with PK index
        try
        {
            System.out.println("Creating Users table with PK index ... ");
            stmt.executeUpdate("CREATE TABLE Users (" +
                                "userID TEXT(20) NOT NULL " +
                                "CONSTRAINT PK_Users PRIMARY KEY, " +
                                "lastName TEXT(30) NOT NULL, " +
                                "firstName TEXT(30) NOT NULL, " +
                                "password TEXT(15), " +
                                "admin BIT" +
                                ")");
        }
        catch(Exception e)
        {
            System.out.println("Exception creating Users table: "
                    + e.getMessage());
        }

        //Create UserStocks table with FK to Users and Stocks table
        try
        {
            System.out.println("Creating UserStocks table ... ");
            stmt.executeUpdate("CREATE TABLE UserStocks (" +
                                "userID TEXT(20) " +
                                "CONSTRAINT FK1_UserStocks " +
                                "REFERENCES Users (userID), " +
                                "symbol TEXT(8), " +
                                "CONSTRAINT FK2_UserStocks " +
                                "FOREIGN KEY (symbol) " +
                                "REFERENCES Stocks (symbol)" +
                                ")");
        }
        catch(Exception e)
        {
            System.out.println("Exception creating UserStocks table: "
                    + e.getMessage());
        }

        //Create UserStocks table PK index
        try
        {
            System.out.println("Creating UserStocks table PK index ... ");
            stmt.executeUpdate("CREATE UNIQUE INDEX PK_UserStocks " +
                                "ON UserStocks (userID, symbol) " //+
                                //"WITH PRIMARY DISALLOW NULL" +
                                );
        }
        catch(Exception e)
        {
            System.out.println("Exception creating UserStocks index: "
                    + e.getMessage());
        }

        //Create one admin user with password as initial data
        String userId = "admin01";
        String firstName = "Default";
        String lastName = "Admin";
        String password = "admin01";
        String initialPassword = "admin01";
        // Will update below when password class is finished
        // Password password = new Password(initialPassword);
        boolean admin = true;

        PreparedStatement pStmt = c.prepareStatement("INSERT INTO Users " +
                "VALUES (?, ?, ?, ?, ?");
        try
        {
            pStmt.setString(1, userId);
            pStmt.setString(2, lastName);
            pStmt.setString(3, firstName);
            pStmt.setString(4, password);
            pStmt.setBoolean(5, admin);
            pStmt.executeUpdate();
        }
        catch(Exception e)
        {
            System.out.println("Exception inserting user: "
                    + e.getMessage());
        }

        pStmt.close();

        // Read and display all User data in the database
        ResultSet rs = stmt.executeQuery("SELECT * FROM Users");

        System.out.println("Database created. \n");
        System.out.println("Displaying data from database ... ");
        System.out.println("Users table contains:");

        // Password will be added when password class is finalized
        // Password passwordFromDB;
        // byte[] buf = null;

        while(rs.next())
        {
            System.out.println("Logon ID       = " + rs.getString("UserID"));
            System.out.println("First name     = " + rs.getString("firstName"));
            System.out.println("Last name      = " + rs.getString("lastName"));
            System.out.println("Admin          = " + rs.getBoolean("admin"));
            System.out.println("Password       = " + initialPassword);

        // Implement when Password class is finished
        // buf = rs.getBytes("pswd");
        // if (buf != null) {
        //    System.out.println("Password Object = " + (pswdFromDB=
            // (Password)deserializeObj(buf)));
        //    System.out.println(" AutoExpires	= "+ pswdFromDB
            // .getAutoExpires()); System.out.println(" Expiring now = "+
            // pswdFromDB.isExpiring()); System.out.println(" Remaining uses = "
        //        + pswdFromDB.getRemainingUses()+"\n");
        //}
        //else
        //    System.out.println("Password Object = NULL!"

        }

        rs = stmt.executeQuery("SELECT * FROM Stocks");
        if(!rs.next())
        {
            System.out.println("Stocks table contains no records.");
        }
        else
            System.out.println("Stocks table still contains no records.");

        rs = stmt.executeQuery("SELECT * FROM UserStocks");
        if(!rs.next())
        {
            System.out.println("UserStocks table contains no records.");
        }
        else
            System.out.println("UserStocks table still contains no records.");

        stmt.close();
    }

    //public static byte[] serializeObj(Object obj)
    //{
    //    ByteArrayOutputStream baOStream = new ByteArrayOutputStream();
    //    ObjectOutputStream objOStream = new ObjectOutputStream(baOStream);
    //
    //    objOStream.writeObject(obj);
    //    objOStream.flush();
    //    objOStream.close();
    //    return baOStream.toByteArray();
    //}
    //
    //public static Object deserializeObj(byte[] buf)
    //{
    //    Object obj = null;
    //    if(buf != null)
    //    {
    //        ObjectInputStream objIStream = new ObjectInputStream(new
    //                ByteArrayInputStream((buf)));
    //        obj = objIStream.readObject();
    //    }
    //    return obj;
    //}
}