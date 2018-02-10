/**
 * An example application that shows a simple connection to a local SQLite
 * database.
 *
 */

// Import statement
import java.sql.*;
// Scanner is for the menu selection
import java.util.Scanner;

public class BasicDBWriter
{
    public static void main(String args[])
    {
        displayMenu();

    }

    public static void connectToDB()
    {
        /**
         * This method will make a connection to a SQLite DB in the same
         * folder. If the DB does not exist then it will be created.
         * Requirements : JDBC jar must exist in the root folder
         * https://bitbucket.org/xerial/sqlite-jdbc/downloads/
         * Error java.lang.ClassNotFoundException: org.sqlite.JDBC could mean
         * the JDBC.jar is not in your compile path.
         *
         * Compile with javac -classpath [JDBC jar file name] BasicDBWriter.java
         * EX : if file is named jdbc.jar, the compile command will be:
         *      javac -classpath jdbc.jar BasicDBWriter.java
         *
         * Run with java -classpath ".:jdbc.jar" BasicDBWriter
         * EX : if the file is named jdbc.jar, the run command will be:
         *      java -classpath ".:jdbc.jar" BasicDBWriter
         */

        // Report method
        System.out.println("\n\n\t--== Connect to DB ==--");
        System.out.println("++ This method tries to connect to the database. " +
                "++");
        System.out.println("------");
        // Create a stub for our connection object. This is how we are going
        // to connect to and interact with our database.
        Connection connection = null;

        // Create a string for our database and path. This will be passed as
        // an argument to the DriverManager.getConnection() method below.
        String databasePath = "jdbc:sqlite:test.db";

        // Using the try and catch pattern we are able to attempt the
        // connection and trap any errors to display.
        try
        {
            // The forName() method allows us to dynamically load a class. In
            // this case we are loading the JDBC driver into memory and
            // registers it into the DriverManager. This driver is what is
            // allowing us to communicate with the SQLite database.
            // Read this for more info:
            // http://www.xyzws.com/Javafaq/what-does-classforname-method-do/17
            Class.forName("org.sqlite.JDBC");

            // Next we need to connect to our database using the connection
            // object stub we created above. Here is how it all goes down.
            // The DriverManager is a list of all registered drivers that
            // have been placed in memory for the program. It is sort of like
            // an array of drivers. The statement below will call the
            // getConnection() method for the supplied path argument, and
            // attempt the connect with every driver listed in
            // DriverManager. So we literally run down the list of registered
            // drivers and if the connection can be made with that driver, it
            // is selected and the connection to that database with that
            // driver is saved in our connection variable.
            connection = DriverManager.getConnection(databasePath);

            // Report successful connection.
            System.out.println("Database connection successful.");
        }
        catch(Exception e)
        {
            // Display any errors that were trapped when we attempted the
            // connection.
            System.out.println("Could not connect to the database ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }

        // Our finally statement will attempt to close the resource.
        finally
        {
            try
            {
                // Closing the connection frees up the resource and prevent
                // the database from being locked while it remains open. if
                // the connection is not null (is not open), close connection.
                if(connection != null)
                    connection.close();

                // Report successful close
                System.out.println("Database connection closed.");
            }
            catch(Exception e)
            {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println( e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void createTable()
    {
        /**
         * This method will make a connection to the database and execute an
         * SQL statement that creates a table.
         */
        // Report method
        System.out.println("\n\n\t--== Create Table ==--");
        System.out.println("++ This method connects to the database and " +
                "creates a table called 'Users'. ++");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object. This stub will eventually
        // holdvan object that allows us to send executable statements to
        // SQLite.
        Statement statementObject = null;

        // Our try and catch statement will look very similar to the one in
        // the connectoToDB() method. We will connect the same way, but then
        // we will have an additional statement to execute our SQL statement.

        try
        {
            // Recall this statement from our connection? We are loading this
            // class that registers the JDBC driver in out DriverManager.
            Class.forName("org.sqlite.JDBC");

            // Here we are setting our connection stub to the successful
            // connection object that we create by passing our database path
            // to the DriverManager.getConnection() method.
            connection = DriverManager.getConnection(databasePath);

            // Inform the user that the connection was successful.
            System.out.println("Database connection successful."
                                + "Attempting to create table ... ");

            // Our connection object has a method called createStatement()
            // that instantiates an object which can pass SQL statements
            // through our open connection to SQLite to be executed.
            statementObject = connection.createStatement();

            // Now that we have an open connection to our database we can
            // send command statements for SQLite to execute. This string will
            // hold the code that we want to execute. Sort of a program within a
            // program.
            // The code below will create a table called 'Users' with 1 int
            // column: ID, and 2 text columns: firstName, lastName.
            // SQL statement tutorials:
            // https://www.tutorialspoint.com/sql/sql-syntax.htm
            // The statement below is excessively broken up for clarity. it
            // could also be written like:
            //      "create table Users (ID int primary key not null,
            //          firstName text not null, lastName text not null)"
            // Note :
            // SQL keywords are case agnostic,
            // names are (potentially depending on the database) case-sensitive
            String sqlStatement = "create table Users"
                            + "("
                            + "ID           int primary key not null, "
                            + "firstName    text not null, "
                            + "lastName     text not null "
                            + ")";

            // Now that we have our SQL statement we need to send it to the
            // database through our statement object. The code below sends
            // and executes the sqlStatement string that we just created.
            statementObject.executeUpdate(sqlStatement);

            // Report a success to the user.
            System.out.println("Table created successfully.");
        }
        catch(Exception e)
        {
            // Here is our catch statement doing its thing. Providing
            // visibility into any errors that were trapped.
            System.out.println("Could not create table ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }

        // Just like before, we have an open connection to the database that
        // we need to close.
        finally
        {
            try
            {
                // Since we have a couple of actions and potential connections
                // happening here we need to ensure that all connections are
                // closed. So we need to close them in the reverse order than
                // how we opened them. So we made the connection, then passed
                // in a statement to be executed. Therefore we need to close
                // out the execution statement, and then close the connection.
                if(statementObject != null)
                    statementObject.close();

                if(connection != null)
                    connection.close();

            }
            catch(Exception e)
            {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println( e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void dropTable()
    {
        /**
         * This method will drop (delete) a table from the database.
         * Only new code will be extensively commented from here out.
         */
        // Report method
        System.out.println("\n\n\t--== Drop Table ==--");
        System.out.println("++ This method connects to the database and " +
                "drops (deletes) the 'Users' table. ++" +
                ".");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object.
        Statement statementObject = null;

        try
        {
            // Register our driver in the DriverManager.
            Class.forName("org.sqlite.JDBC");

            // Try to get a successful connection
            connection = DriverManager.getConnection(databasePath);

            System.out.println("Database connection successful. "
                                + "Attempting to drop table ... ");

            // Create our statement object so we can execute SQL statements
            // on the database connection.
            statementObject = connection.createStatement();

            // Create our SQL statement to drop (delete) the table.
            String sqlStatement = "drop table Users";

            // Execute the statement we just built
            statementObject.executeUpdate(sqlStatement);

            // Report a success to the user.
            System.out.println("Table dropped successfully.");

        }
        catch(Exception e)
        {
            // Display any errors that were trapped when we attempted to
            // close the connection.
            System.out.println("Could not drop table ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }
        // Here is our trusty finally statement that allows us to clean
        // things up and close all of our open connections.
        finally
        {
            try
            {
                // Close our connections in reverse order.
                if(statementObject != null)
                    statementObject.close();

                if(connection != null)
                    connection.close();

            }
            catch(Exception e)
            {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println( e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void insertToTable()
    {
        /**
         * Inserting information into a table uses the same connection,
         * statement building, and execution steps we have been seeing.
         * Comments are only going to be used for new concepts.
         */

        // Report method
        System.out.println("\n\n\t--== Insert Into Table ==--");
        System.out.println("++ This method inserts a record into the 'Users' " +
                "table. The record contains the following data \n ID: 1 " +
                "FirstName: Jeramy LastName: D. ++");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object.
        Statement statementObject = null;

        try
        {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(databasePath);

            System.out.println("Database connection successful. "
                    + "Attempting to insert data ... ");
            // I want to control when my DB is saved, so I am disabling
            // autoCommit with the first statement. With autocommit enabled,
            // the data you are writing to the table will be saved
            // immediately. With it disabled you will need to explicitly call
            // the commit (save) command to finalize your data to the table.
            connection.setAutoCommit(false);

            statementObject = connection.createStatement();

            // Create our SQL statement to insert a record.
            String sqlStatement = "insert into Users "
                                + "(ID, firstName, lastName)"
                                + "values (1, 'Jeramy', 'D' );";

            // Execute the statement we just built
            statementObject.executeUpdate(sqlStatement);

            // While the exception put the new data into the table, we
            // haven't saved, or committed, the data to the table yet
            // (Because we turned autocommit off) The commit command saves the
            // changes to the table and finalizes everything.
            connection.commit();

            // Report a success to the user.
            System.out.println("Information inserted successfully.");
        }
        catch(Exception e)
        {
            // Display any errors that were trapped when we attempted to
            // close the connection.
            System.out.println("Could not insert records ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }
        finally
        {
            try
            {
                // Close our connections in reverse order.
                if(statementObject != null)
                    statementObject.close();

                if(connection != null)
                    connection.close();

            }
            catch(Exception e)
            {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println( e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void updateRecord()
    {
        /**
         * There are times when you just need to update date for a record.
         * The update keyword allows this.
         */

        // Report method
        System.out.println("\n\n\t--== Update Table Record ==--");
        System.out.println("++ This method updates the existing record in the " +
                "'Users' table and changes LastName from 'D' to 'Dichiera'. " +
                "++");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object.
        Statement statementObject = null;

       try
       {
           Class.forName("org.sqlite.JDBC");
           connection = DriverManager.getConnection(databasePath);

           System.out.println("Database connection successful. "
                   + "Attempting to update data ... ");

           // Turn autocommit off so we control when the data is committed
           // to the table.
           connection.setAutoCommit(false);

           statementObject = connection.createStatement();

           // Build our SQL statement to execute. The keyword update lets the
           // database know that we want to change data. Then we set the
           // field to the new value. The way we tell the database what row
           // we want to update is by using the where statement to tell it
           // which value to look for. We could also do something like this:
           //  update Users set lastName = 'Dichiera' where firstName = 'Jeramy'
           String sqlStatement = "update Users "
                                +"set lastName = 'Dichiera' "
                                +"where ID = 1;";

           // Execute the SQL statement
           statementObject.executeUpdate(sqlStatement);

           // Commit the changes
           connection.commit();

           // Report a success to the user.
           System.out.println("Record updated successfully.");

       }
       catch(Exception e)
       {
           System.out.println("Could not update record ... \n");
           System.err.println( e.getClass().getName() + ": " + e.getMessage());
           //System.exit(0);
       }
       // Close up shop!
       finally
       {
           try
           {
               // Close our connections in reverse order.
               if(statementObject != null)
                   statementObject.close();

               if(connection != null)
                   connection.close();

           }
           catch(Exception e)
           {
               // Display any errors that were trapped when we attempted to
               // close the connection.
               System.out.println("Could not close to the database ... \n");
               System.err.println( e.getClass().getName() + ": " + e.getMessage());
               //System.exit(0);
           }
       }
        displayMenu();
    }


    public static void deleteRecord()
    {
        /**
         * This method will delete a record from the database table. It works
         * similarly to the update command.
         */

        // Report method
        System.out.println("\n\n\t--== Delete Table Record ==--");
        System.out.println("++ This method deletes the record from the 'Users'" +
                " table. ++");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object.
        Statement statementObject = null;

        try
        {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(databasePath);

            System.out.println("Database connection successful. "
                    + "Attempting to delete record ... ");

            // Turn autocommit off so we control when the data is committed
            // to the table.
            connection.setAutoCommit(false);

            statementObject = connection.createStatement();

            // Build our SQL statement to execute. We use the delete keyword
            // to delete the record that is located with our where statement
            String sqlStatement = "delete from Users where ID = 1;";

            // Execute the SQL statement
            statementObject.executeUpdate(sqlStatement);

            //Commit our change
            connection.commit();

            System.out.println("Record deleted successfully.");
        }
        catch(Exception e)
        {
            System.out.println("Could not delete record ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }
        finally
        {
            try {
                // Close our connections in reverse order.
                if (statementObject != null)
                    statementObject.close();

                if (connection != null)
                    connection.close();

            } catch (Exception e) {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void selectRecords()
    {
        /**
         * You use the select keyword to select records to print out to the
         * screen. The selection you gather from the database will be saved
         * in a results object which you can use to print from.
         */

        // Report method
        System.out.println("\n\n\t--== Select From Table ==--");
        System.out.println("++ This method selects all (1) records from the " +
                "'Users' table and prints them out. ++");
        System.out.println("------");

        // Create a stub for our connection and database path.
        Connection connection = null;
        String databasePath = "jdbc:sqlite:test.db";

        //Create a stub for our SQL statement object.
        Statement statementObject = null;

        try
        {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection(databasePath);

            System.out.println("Database connection successful. "
                    + "Attempting to select records ... ");

            connection.setAutoCommit(false);

            statementObject = connection.createStatement();

            // We use a ResultSet object to store the data retrieved from the
            // database. Select * selects all records that exist in the
            // stated table and returns them to the ResultSet object.
            ResultSet results =
                    statementObject.executeQuery("select * from Users");

            System.out.println("Records retrieved successfully.");

            // Now that we have the table data saved in the ResultSet object,
            // we can loop through it like any other collection and print out
            // the data.
            // While there is a next line in the results collection.

            // Im closing the results object here since it does not exist
            // anymore when I get to the finally statement. Unsure why.
            results.close();

            while(results.next())
            {
                // Save the records data into variables for easier use.
                int id = results.getInt("ID");
                String firstName = results.getString("firstName");
                String lastName = results.getString("lastName");

                // Print out the values
                System.out.println("--==Users Table Data==--");
                System.out.print("ID: " + id
                                + " FirstName: " + firstName
                                + " LastName: " + lastName + "\n");
            }
        }
        catch(Exception e)
        {
            System.out.println("Could not retrieve records ... \n");
            System.err.println( e.getClass().getName() + ": " + e.getMessage());
            //System.exit(0);
        }
        finally
        {
            try {

                // Close our connections in reverse order.
                if (statementObject != null)
                    statementObject.close();

                if (connection != null)
                    connection.close();

            } catch (Exception e) {
                // Display any errors that were trapped when we attempted to
                // close the connection.
                System.out.println("Could not close to the database ... \n");
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                //System.exit(0);
            }
        }
        displayMenu();
    }


    public static void displayMenu()
    {
        /**
         * Menu for easier navigation
         */
        System.out.println("\n\n\t--== Main Menu ==--");
        System.out.println("1. Connect to Database");
        System.out.println("2. Create Table");
        System.out.println("3. Drop Table");
        System.out.println("4. Insert Record");
        System.out.println("5. Update Record");
        System.out.println("6. Delete Record");
        System.out.println("7. Select Records");
        System.out.println("8. Quit");

        Scanner reader = new Scanner(System.in);
        int menuSelection = reader.nextInt();

        switch(menuSelection)
        {
            case 1:
                connectToDB();
                break;
            case 2:
                createTable();
                break;
            case 3:
                dropTable();
                break;
            case 4:
                insertToTable();
                break;
            case 5:
                updateRecord();
                break;
            case 6:
                deleteRecord();
                break;
            case 7:
                selectRecords();
                break;
            case 8:
                exit();
                break;
        }
    }


    public static void exit()
    {
        /**
         * You all know what this does right?
         */
        System.out.println("__Exiting Program__");
        System.exit(0);

    }


}