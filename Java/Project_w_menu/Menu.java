/**
 * This program is the basic menu options for the class project
 */


import java.util.Scanner;


public class ProjectArray{
    public static void main(String args[]){
        displayMenu();
    }


    public static void displayMenu(){
        /**
         * Displays the main menu and holds the switch statement that is
         * controlled by the user input.
         */
        int menuChoice = 0;
        int numberMenuChoices = 5;

        System.out.println("--== Stock Menu Program ==--");
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
                fullUserList();
                break;
            case 4:
                fullStockList();
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

    public static void fullUserList(){
        System.out.println("User List");
        displayMenu();
    }

    public static void fullStockList(){
        System.out.println("Stock List");
        displayMenu();
    }


    public static void quit(){
        /**
         * Quits the program
         */
        System.out.println("Exiting Program ...");
        System.exit(0);
    }
}