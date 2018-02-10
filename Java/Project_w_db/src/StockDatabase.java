/**
 * Created by udichje on 5/7/17.
 */

import java.io.*;
import java.sql.*;
import java.util.*;

public class StockDatabase
{
    private Connection connection = null;

    public StockDatabase() throws ClassNotFoundException, SQLException{
        if(connection == null){
            String driverPath = "org.sqlite.JDBC";
            String databasePath = "jdbc:sqlite:StockDatabase.db";

            try
            {
                Class.forName(driverPath);
            }
            catch (ClassNotFoundException e)
            {
                System.out.println("Connection error ... :");
                throw new ClassNotFoundException(e.getMessage());
            }


            try
            {
                connection = DriverManager.getConnection(databasePath);
            }
            catch (SQLException e)
            {
                throw new SQLException(e.getMessage());
            }
        }
    }

    public void close() throws SQLException,IOException,ClassNotFoundException{
        connection.close();
        connection = null;
    }

    private byte[] serializeObject(Object obj) throws IOException{
        ByteArrayOutputStream baOStream = new ByteArrayOutputStream();
        ObjectOutputStream objOStream = new ObjectOutputStream(baOStream);

        objOStream.writeObject(obj);
        objOStream.flush();
        objOStream.close();
        return baOStream.toByteArray();
    }

    private Object deserializeObj(byte[] buf) throws IOException,
            ClassNotFoundException{
        Object obj = null;

        if (buf != null){
            ObjectInputStream objIStream = new ObjectInputStream((new
                    ByteArrayInputStream(buf)));
            obj = objIStream.readObject();
        }
        return obj;
    }

    public void addStock(String stockSymbol, String stockDescription) throws
            SQLException, IOException, ClassNotFoundException{
        Statement statement = connection.createStatement();
        statement.executeUpdate("INSERT INTO Stocks VALUES ('" + stockSymbol
                + "'" + ",'" + stockDescription + "')");
        statement.close();
    }

    public boolean addUser(User user) throws SQLException, IOException,
            ClassNotFoundException{
        boolean result = false;
        String dbUserID;
        String dbFirstName;
        String dbLastName;
        String dbPassword;
        int isAdmin;

        dbUserID = user.getUserID();

        if (getUser(dbUserID) == null){
            dbFirstName = user.getFirstName();
            dbLastName = user.getLastName();
            dbPassword = user.getPassword();
            isAdmin = user.getIsAdmin();

            PreparedStatement pStatement = connection.prepareStatement
                    ("INSERT INTO Users VALUES (?,?,?,?,?)");

            pStatement.setString(1, dbUserID);
            pStatement.setString(2, dbFirstName);
            pStatement.setString(3, dbLastName);
            pStatement.setString(4, dbPassword);
            pStatement.setInt(5, isAdmin);

            pStatement.executeUpdate();
            pStatement.close();
            result = true;
        }
        else {
            throw new IOException("User exists - cannot add.");
        }
        return result;
    }


    public boolean updateUser(User user) throws SQLException, IOException,
            ClassNotFoundException{
        boolean result = false;
        String dbUserID;
        String dbFirstName;
        String dbLastName;
        String dbPassword;
        int isAdmin;

        dbUserID = user.getUserID();

        if (getUser(dbUserID) == null){
            dbFirstName = user.getFirstName();
            dbLastName = user.getLastName();
            dbPassword = user.getPassword();
            isAdmin = user.getIsAdmin();

            PreparedStatement pStatement = connection.prepareStatement
                    ("UPDATE Users SET firstName = ?, lastName = ?, password " +
                            "= ?, admin = ? WHERE userID = ?");

            pStatement.setString(1, dbUserID);
            pStatement.setString(2, dbFirstName);
            pStatement.setString(3, dbLastName);
            pStatement.setString(4, dbPassword);
            pStatement.setInt(5, isAdmin);

            pStatement.executeUpdate();
            pStatement.close();
            result = true;
        }
        else {
            throw new IOException("User cannot be updated.");
        }
        return result;
    }

    private void delStock(String stockSymbol) throws SQLException,
            IOException, ClassNotFoundException{
        Statement statement = connection.createStatement();
        statement.executeUpdate("DELETE FROM Stocks WHERE symbol = '" +
                stockSymbol + "'");
        statement.close();
    }

    public void delUser(User user) throws SQLException, IOException,
            ClassNotFoundException{
        String dbUserID;
        String stockSymbol;
        Statement statement = connection.createStatement();
        try
        {
            connection.setAutoCommit(false);

            dbUserID = user.getUserID();
            if(getUser(dbUserID) != null){
                ResultSet result1 = statement.executeQuery("SELECT userID, " +
                        "symbol FROM UserStocks WHERE userID = '" + dbUserID
                        + "'");
                while(result1.next()){
                    try
                    {
                        stockSymbol = result1.getString("symbol");
                        delUserStocks(dbUserID, stockSymbol);
                    }
                    catch (SQLException e)
                    {
                        throw new SQLException("Delection of user stock " +
                                "holding failed: " + e.getMessage());
                    }
                }
                try
                {
                    statement.executeUpdate("DELETE FROM Users WHERE " +
                            "userID = '" + dbUserID + "'");
                }
                catch (SQLException e)
                {
                    throw new SQLException("User deletion failed: "
                            + e.getMessage());
                }
            }
            else{
                throw new IOException("User not found in database - cannot " +
                        "delete.");
            }
            try
            {
                connection.commit();
            }
            catch (SQLException e)
            {
                throw new SQLException("Transaction commit failed : "
                        + e.getMessage());
            }
        }
        catch (SQLException e)
        {
            try
            {
                connection.rollback();
            }
            catch (SQLException se)
            {
                throw new SQLException(("Transaction failed then rollback " +
                        "failed: " + se.getMessage()));
            }
            throw new SQLException("Transaction failed; was rolled back: " +
                    e.getMessage());
        }
        statement.close();
    }


    public void delUserStocks(String userID, String stockSymbol) throws
            SQLException, IOException, ClassNotFoundException{
        Statement statement = connection.createStatement();
        ResultSet results;

        statement.executeUpdate("DELETE FROM UserStocks WHERE " +
                "userID = '" +
                userID + "'" + "AND symbol = '" + stockSymbol + "'");

        results =statement.executeQuery("SELECT symbol FROM UserStocks WHERE " +
                "symbol = " + stockSymbol + "'");

        if(!results.next()){
            delStock(stockSymbol);
        }
        statement.close();
    }

    public void addUserStock(String userID, String stockSymbol) throws
            SQLException, IOException, ClassNotFoundException{
        Statement statement = connection.createStatement();

        System.out.println("INSERT INTO UserStocks VALUES ("+
                userID + ",'" + stockSymbol + "'");
        statement.executeUpdate("INSERT INTO UserStocks VALUES ("+
                userID + ",'" + stockSymbol + "')");

        statement.close();
    }

    public String getStockDescription(String stockSymbol) throws
            SQLException, IOException, ClassNotFoundException{
        Statement statement = connection.createStatement();
        String stockDescription = null;

        ResultSet results = statement.executeQuery("SELECT symbol, name FROM " +
                "Stocks WHERE symbol = '" + stockSymbol + "'");

        if(results.next()){
            stockDescription = results.getString("name");
        }
        results.close();
        statement.close();
        return stockDescription;
    }

    public User getUser(String userID) throws SQLException, IOException,
            ClassNotFoundException{
        Statement statement = connection.createStatement();

        String dbUserID;
        String dbFirstName;
        String dbLastName;
        String dbPassword;
        int isAdmin;

        byte[] buf = null;
        User user = null;
        ResultSet results = statement.executeQuery("SELECT * FROM Users WHERE" +
                " userID = '" + userID + "'");

        if(results.next()){
            dbUserID = results.getString("userID");
            dbFirstName = results.getString("firstName");
            dbLastName = results.getString("lastName");
            dbPassword = results.getString("password");
            isAdmin = results.getInt("admin");
            user = new User(dbUserID, dbFirstName, dbLastName, dbPassword,
                    isAdmin);
        }
        results.close();
        statement.close();

        return user;
    }

    public ArrayList listUsers() throws SQLException, IOException,
            ClassNotFoundException{
        ArrayList list = new ArrayList();
        Statement statement = connection.createStatement();

        ResultSet results = statement.executeQuery("SELECT userID, firstName," +
                " lastName, admin FROM Users ORDER BY userID");

        while(results.next()){
            list.add(results.getString("userID"));
            list.add(results.getString("firstName"));
            list.add(results.getString("lastName"));
            list.add(results.getInt("admin"));
        }
        results.close();
        statement.close();

        return list;
    }


    public ArrayList listUserStocks(String userID) throws SQLException,
            IOException, ClassNotFoundException{
        ArrayList list = new ArrayList();
        Statement statement = connection.createStatement();

        ResultSet results = statement.executeQuery("SELECT * FROM UserStocks " +
                "WHERE userID = " + userID + " ORDER BY symbol");

        System.out.println("++ User Stock List ++");
        while(results.next()){
            list.add(results.getString("symbol"));
        }
        System.out.println("++++");
        results.close();
        statement.close();

        return list;
    }

}
