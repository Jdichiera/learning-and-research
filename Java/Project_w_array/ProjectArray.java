/**
 * This program extends the menu assignment with an arraylist and classes
 */


import java.util.Scanner;
import java.util.*;


public class ProjectArray{
    public static void main(String args[]){
        System.out.println("s");
        displayMenu();
    }


    public static void displayMenu(){
        /**
         * Displays the main menu and holds the switch statement that is
         * controlled by the user input.
         */
        ArrayList<Stock> stockArray = new ArrayList<Stock>();
        ArrayList<NormalUser> normalUserArray = new ArrayList<NormalUser>();
        ArrayList<AdminUser> adminUserArray = new ArrayList<AdminUser>();

        stockArray = fillStockArray();
        normalUserArray = fillNormalUserArray();
        adminUserArray = fillAdminUserArray();

        int menuChoice = 0;
        int numberMenuChoices = 5;

        System.out.println("\n--== Stock Menu Program ==--");
        System.out.println("1. User Options");
        System.out.println("2. Stock Options");
        System.out.println("3. Full User List");
        System.out.println("4. Full Stock List");
        System.out.println("5. Exit Program");

        menuChoice = getMenuSelection(numberMenuChoices);

        switch(menuChoice){
            case 1:
                userOptionMenu();
                break;
            case 2:
                stockOptionMenu();
                break;
            case 3:
                fullUserList(normalUserArray, adminUserArray);
                break;
            case 4:
                fullStockList(stockArray);
                break;
            case 5:
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

        switch(menuChoice){
            case 1:
                System.out.println("User Details");
                userOptionMenu();
                break;
            case 2:
                System.out.println("Add User");
                userOptionMenu();
                break;
            case 3:
                System.out.println("Update User");
                userOptionMenu();
                break;
            case 4:
                System.out.println("Delete User");
                userOptionMenu();
                break;
            case 5:
                System.out.println("Get User Stocks");
                userOptionMenu();
                break;
            case 6:
                System.out.println("Add User Stocks");
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

        System.out.println("\n--== Stock Menu Program ==--");
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

    public static void fullUserList(ArrayList<NormalUser> normalUserArrayList,
                                    ArrayList<AdminUser> adminUserArrayList){
        System.out.println("\n\t--== Normal User List ==--");
        for(NormalUser user : normalUserArrayList)
            System.out.println( "ID: " + user.getUserId() + " ; " +
                                "FirstName: " + user.getFirstName() + " ; " +
                                "LastName: " + user.getLastName() + " ; " +
                                "Password : ***** ");
            //System.out.println(user);
        System.out.println("\n\t--== Admin User List ==--");
        for(AdminUser user : adminUserArrayList)
            System.out.println("ID: " + user.getUserId() + " ; " +
                                "FirstName: " + user.getFirstName() + " ; " +
                                "LastName: " + user.getLastName() + " ; " +
                                "Password : ***** ");
        displayMenu();
    }

    public static void fullStockList(ArrayList<Stock> stockArray){
        System.out.println("\n\t--== Stock List ==--");
        for(Stock stock : stockArray)
            System.out.println( "Symbol: " + stock.getSymbol() +  " ; " +
                                "Description: " + stock.getDescription());
        displayMenu();
    }


    public static void quit(){
        /**
         * Quits the program
         */
        System.out.println("Exiting Program ...");
        System.exit(0);
    }

    public static ArrayList<Stock> fillStockArray(){
        ArrayList<Stock> stockArray = new ArrayList<Stock>();

        Stock aStock = new Stock("AAA", "A Company Stock");
        Stock bStock = new Stock("BBB", "B Company Stock");
        Stock cStock = new Stock("CCC", "C Company Stock");

        stockArray.add(aStock);
        stockArray.add(bStock);
        stockArray.add(cStock);

        return stockArray;
    }

    public static ArrayList<NormalUser> fillNormalUserArray(){
        ArrayList<NormalUser> normalUserArray = new ArrayList<NormalUser>();

        NormalUser user1 = new NormalUser(1, "First1", "Last1",
                "pass1");
        NormalUser user2 = new NormalUser(2, "First2", "Last2",
                "pass2");
        NormalUser user3 = new NormalUser(3, "First3", "Last3",
                "pass3");

        normalUserArray.add(user1);
        normalUserArray.add(user2);
        normalUserArray.add(user3);

        return normalUserArray;
    }

    public static ArrayList<AdminUser> fillAdminUserArray(){
        ArrayList<AdminUser> adminUserArray = new ArrayList<AdminUser>();

        AdminUser admin1 = new AdminUser(91, "FirstAdmin1", "LastAdmin1",
                "passAdmin1");
        AdminUser admin2 = new AdminUser(92, "FirstAdmin2", "LastAdmin2",
                "passAdmin2");
        AdminUser admin3 = new AdminUser(93, "FirstAdmin3", "LastAdmin3",
                "passAdmin3");

        adminUserArray.add(admin1);
        adminUserArray.add(admin2);
        adminUserArray.add(admin3);

        return adminUserArray;
    }
}