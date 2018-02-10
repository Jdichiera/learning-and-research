
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;
import java.util.*;

public class Menu{
    public static void main(String args[]){
        displayMenu();
    }

    public static void displayMenu(){
        /**
         * Displays the main menu and holds the switch statement that is
         * controlled by the user input.
         */

        int menuChoice = 0;
        int numberMenuChoices = 7;
        String initChoice;
        boolean token = true;

        System.out.println("\n\n--== Stock Menu Program ==--");
        System.out.println("1. User Options");
        System.out.println("2. Stock Options");
        System.out.println("3. Full User List");
        System.out.println("4. Full Stock List");
        System.out.println("5. Initialize Database");
        System.out.println("6. Show Tables");
        System.out.println("7. Exit Program");

        menuChoice = getMenuSelection(numberMenuChoices);

        switch(menuChoice){
            case 1:
                userOptionMenu();
                break;
            case 2:
                stockOptionMenu();
                break;
            case 3:
                //fullUserList();
                break;
            case 4:
                //fullStockList();
                break;
            case 5:
                MakeDB makedb = new MakeDB();
                try
                {
                    makedb.MakeDB();
                    displayMenu();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }

                break;
            case 6:
                //showTables();
                break;
            case 7:
                quit();
                break;
        }
    }


    public static void userOptionMenu(){
        /**
         * Displays the user submenu and holds the switch statement that is
         * controlled by the user input.
         */
        int menuChoice = 0;
        int numberMenuChoices = 8;

        System.out.println("--== User Menu Program ==--");
        System.out.println("1. Get User Details");
        System.out.println("2. Add New User");
        System.out.println("3. Update User");
        System.out.println("4. Delete User");
        System.out.println("5. Get User Stocks");
        System.out.println("6. Add User Stocks");
        System.out.println("7. Remove User Stocks");
        System.out.println("8. Return to Main Menu");

        menuChoice = getMenuSelection(numberMenuChoices);

        StockDatabase database;
        User user = null;
        Scanner scanner = null;

        switch(menuChoice){
            case 1:
                //Checked
                System.out.println("User Details");
                scanner = new Scanner(System.in);
                System.out.println("Enter user ID");

                String userId = scanner.nextLine();
                try
                {
                    database = new StockDatabase();
                    user = database.getUser(userId);
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }

                if(user != null){
                    printUser(user);
                }else{
                    System.out.println("No user returned");
                }
                userOptionMenu();
                break;
            case 2:
                //Checked
                user = createUser();
                try
                {
                    database = new StockDatabase();
                    database.addUser(user);
                    database.getUser(user.getUserID());
                    System.out.println("++User Added++");
                    printUser(user);
                    System.out.println("++++");
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
                userOptionMenu();
                break;
            case 3:
                //Checked
                System.out.println("Update User");
                try
                {
                    scanner = new Scanner(System.in);
                    database = new StockDatabase();
                    System.out.println("Enter the user ID that needs update");
                    userId = scanner.nextLine();
                    user = database.getUser(userId);
                    System.out.println("++Current User Details++");
                    printUser(user);
                    System.out.println("++++");
                    System.out.println("Enter new FirstName");
                    user.setFirstName(scanner.nextLine());
                    System.out.println("Enter new LastName");
                    user.setLastName(scanner.nextLine());
                    System.out.println("Enter new Password");
                    user.setPassword(scanner.nextLine());
                    boolean success = database.updateUser(user);
                    System.out.println(success);
                    System.out.println("++NEW User Details++");
                    printUser(user);
                    System.out.println("++++");
                }
                catch (Exception e)
                {
                    e.getMessage();
                }
                userOptionMenu();
                break;
            case 4:
                //Checked
                System.out.println("Delete User");
                try
                {
                    scanner = new Scanner(System.in);
                    database = new StockDatabase();
                    System.out.println("Enter the user ID that needs update");
                    userId = scanner.nextLine();
                    user = database.getUser(userId);
                    database.delUser(user);
                }
                catch (Exception e)
                {
                    e.getMessage();
                }

                System.out.println("Enter the user ID that needs update");
                userOptionMenu();
                break;
            case 5:
                //Checked
                System.out.println("Get User Stocks");
                try
                {
                    scanner = new Scanner(System.in);
                    database = new StockDatabase();
                    System.out.println("Enter user ID for stock list");
                    userId = scanner.nextLine();
                    database.listUserStocks(userId);
                }
                catch (Exception e)
                {
                    e.getMessage();
                }
                userOptionMenu();
                break;
            case 6:
                System.out.println("Add User Stocks");
                try
                {
                    scanner = new Scanner(System.in);
                    database = new StockDatabase();
                    System.out.println("Enter user ID to add stock to");
                    userId = scanner.nextLine();
                    System.out.println("Enter stock symbol to add");
                    String symbol = scanner.nextLine();
                    database.addUserStock(userId, symbol);
                }
                catch (Exception e)
                {
                    e.getMessage();
                }
                userOptionMenu();
                break;
            case 7:
                System.out.println("Remove User Stocks");
                userOptionMenu();
                break;
            case 8:
                System.out.println("Returning to Main Menu");
                displayMenu();
                break;
        }
    }

    public static void stockOptionMenu(){
        /**
         * Displays the stock submenu and holds the switch statement that is
         * controlled by the user input.
         */
        int menuChoice = 0;
        int numberMenuChoices = 4;

        System.out.println("--== Stock Menu Program ==--");
        System.out.println("1. Get Stock Details");
        System.out.println("2. Add New Stock");
        System.out.println("3. Delete Stock");
        System.out.println("4. Return to Main Menu");

        menuChoice = getMenuSelection(numberMenuChoices);

        switch(menuChoice){
            case 1:
                System.out.println("Stock Details");
                stockOptionMenu();
                break;
            case 2:
                System.out.println("Add New Stock");
                stockOptionMenu();
                break;
            case 3:
                System.out.println("Delete Stock");
                stockOptionMenu();
                break;
            case 4:
                System.out.println("Returning to Main Menu");
                displayMenu();
                break;
        }
    }


    public static int getMenuSelection(int maxOption){
        /**
         * Promts the user for input. If the input is not between 1 and the
         * max options then the user is prompted again.
         */
        Scanner reader = new Scanner(System.in);
        int selection = 0;

        do{
            try{
                if((selection > 0) && (selection <= maxOption))
                    break;
                else{
                    System.out.println("\nPlease make a selection from the " +
                            "menu: (1 - " + maxOption + ")");
                    String input = reader.nextLine();
                    selection = Integer.parseInt(input);
                }
            }catch(Exception e){
                System.out.println("\nPlease make a selection from the menu " +
                        ": (1 - " + maxOption + ")");
            }
        }
        while(true);

        return selection;
    }


    public static User createUser(){
        Scanner scanner = new Scanner(System.in);
        String userId;
        String firstName;
        String lastName;
        String password;
        int admin;

        System.out.println("--== Create New User ==--");
        System.out.println("Please enter user ID");
        userId = scanner.nextLine();
        System.out.println("Please enter user First Name");
        firstName = scanner.nextLine();
        System.out.println("Please enter user Last Name");
        lastName = scanner.nextLine();
        System.out.println("Please enter user Password");
        password = scanner.nextLine();
        System.out.println("Is the user an admin?");
        admin = scanner.nextInt();

        User user = new User(userId, firstName, lastName, password, admin);
        return user;
    }

    public static void printUser(User user){
        System.out.println("User ID: " + user.getUserID());
        System.out.println("User FirstName: " + user.getFirstName());
        System.out.println("User LastName: " + user.getLastName());
        System.out.println("User Password: ****");
        System.out.println("User Admin: " + user.getIsAdmin());
    }
    public static void quit(){
        /**
         * Quits the program
         */
        System.out.println("Exiting Program ...");
        System.exit(0);
    }
}
