/**
 * This program takes user input, calculates the area of a square, rectangle,
 * or triangle, or the circumference of a circle, and displays the value to
 * the user.
 */


import javax.swing.JOptionPane;
import java.util.Scanner;


public class Calculator{
    public static void main(String args[]){
        displayMenu();
    }


    public static void displayMenu(){
        /**
         * Displays the main menu and holds the switch statement that is
         * controlled by the user input.
         */
        int menuChoice = 0;

        System.out.println("--== Shape Area Calculator ==--");
        System.out.println("\nThis program will output the area or " +
                "circumference based on user input.\n");
        System.out.println("1. Calculate Area of a Square");
        System.out.println("2. Calculate Area of a Rectangle");
        System.out.println("3. Calculate Area of a Triangle");
        System.out.println("4. Calculate Circumference of a Circle");
        System.out.println("5. Exit Program");

        menuChoice = getMenuSelection();

        switch(menuChoice){
            case 1:
                calculateSquare();
                break;
            case 2:
                calculateRectangle();
                break;
            case 3:
                calculateTriangle();
                break;
            case 4:
                calculateCircle();
                break;
            case 5:
                quit();
                break;
        }
    }


    public static int getMenuSelection(){
        /**
         * Promts the user for input. If the input is not between 1 and 5
         * then the user is prompted again.
         */
        Scanner reader = new Scanner(System.in);
        int selection = 0;

        do{
            try{
                if((selection > 0) && (selection < 6))
                    break;
                else{
                    System.out.println("\nPlease make a selection from the " +
                            "menu (1 - 5):");
                    String input = reader.nextLine();
                    selection = Integer.parseInt(input);
                }
            }catch(Exception e){
                System.out.println("\nPlease make a selection from the menu " +
                        "(1 - 5):");
            }
        }
        while(true);

        return selection;
    }


    public static double getShapeInput(){
        /**
         * Prompts the user to enter a numeric input for the shape calculation
         */
        Scanner reader = new Scanner(System.in);
        double shapeInput = 0.0;

        do{
            try{
                if(shapeInput > 0)
                    break;
                else{
                    String input = reader.nextLine();
                    shapeInput = Double.parseDouble(input);
                }
            }catch(Exception e){
                System.out.println("\nplease enter numeric input: ");
            }
        }
        while(true);

        return shapeInput;
    }


    public static void calculateSquare(){
        /**
         * Calculates the area of a square and displays it to the user
         */
        double side = 0;
        double answer = 0;

        System.out.println("\n\t--== Calculate Area of a Square ==--");
        System.out.println("Please enter the length of a side: ");
            side = getShapeInput();

        answer = side * side;

        System.out.println("Calculating area (A = side * side) : " + side +
                " * " + side + " = " + answer);
        System.out.println("\nThe area of the square is: " + answer + ".");

        checkUserContinue();
    }


    public static void calculateRectangle(){
        /**
         * Calculates the area of a rectangle and displays it to the user
         */
        double width = 0.0;
        double length = 0.0;
        double answer = 0;

        System.out.println("\n\t--== Calculate Area of a Rectangle ==--");
        System.out.println("Please enter the length of the rectangle: ");
            width = getShapeInput();

        System.out.println("Please enter the width of the rectangle: ");
            length = getShapeInput();

        answer = length * width;

        System.out.println("Calculating area (A = length * width) : " +
                length + " * " + width + " = " + answer);
        System.out.println("\nThe area of the rectangle is: " + answer + ".");

        checkUserContinue();
    }


    public static void calculateTriangle(){
        /**
         * Calculates the area of a triangle and displays it to the user
         */
        double base = 0.0;
        double height = 0.0;
        double answer = 0;

        System.out.println("\n\t--== Calculate Area of a Triangle ==--");
        System.out.println("Please enter the base of the triangle: ");
            base = getShapeInput();

        System.out.println("Please enter the height of the triangle: ");
            height = getShapeInput();

        answer = (base * height) / 2;

        System.out.println("Calculating area (A = (base * height) / 2 ):" +
                " (" + base + " * " + height + ") / 2 = " + answer);
        System.out.println("\nThe area of the triangle is: " + answer + ".");

        checkUserContinue();
    }


    public static void calculateCircle(){
        /**
         * Calculates the circumference of a circle and displays it to the user
         */
        double radius = 0.0;
        double answer = 0;

        System.out.println("\n\t--== Calculate Circumference of a Circle ==--");
        System.out.println("Please enter the radius of the circle: ");
            radius = getShapeInput();

        answer = 2 * Math.PI * radius;

        answer = Math.round(answer * 100.0) / 100.0;

        System.out.println("Calculating circumference (C = 2 * Pi * radius) :" +
                " 2 * Pi * " + radius +  " = " + answer + "\n(answer rounded " +
                "to the nearest hundredth)");
        System.out.println("\nThe circumference of the circle is: " + answer +
                ".");

        checkUserContinue();
    }


    public static void checkUserContinue(){
        /**
         * Gives the user a choice to exit the program or do an additional
         * calculation
         */
        Scanner reader = new Scanner(System.in);
        String userChoice = null;

        System.out.println("\nDo you want to do another calculation? (Y/N) : ");
            userChoice = reader.nextLine();

        while((!userChoice.equalsIgnoreCase("Y")) && (!userChoice
                .equalsIgnoreCase("N"))){
            System.out.println("\nPlease enter Y or N : ");
            userChoice = reader.nextLine();
        }

        if(userChoice.equalsIgnoreCase("Y"))
            displayMenu();
        else
            quit();
    }


    public static void quit(){
        /**
         * Quits the program
         */
        System.out.println("Exiting Program ...");
        System.exit(0);
    }
}