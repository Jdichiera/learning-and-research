/**
 * This program takes 10 int numbers from the user and puts those numbers
 * into an
 * array. The array is searched and the largest and smallest numbers are
 * printed out.
 */


import java.util.Scanner;


public class Highlow{
    public static void main(String args[]){
        int numberArray[] = new int[10];

        numberArray = fillArray();
        printArray(numberArray);
        printArrayLowHigh(numberArray);
    }


    public static int[] fillArray(){
        /**
         * This function takes 10 numbers from the user and puts them into an
         * array that is returned at the end of the function. Only integer
         * numbers are accepted.
         */
        Scanner reader = new Scanner(System.in);
        int array[] = new int[10];

        System.out.println("Please enter 10 non-negative whole numbers.");

        for(int i = 0; i < 10; i++){
            do{
                System.out.println("\nNumber " + (i + 1) + ": ");
                while(!reader.hasNextInt()){
                    System.out.println("\nThe number should be a non-negative" +
                            " whole number... try again.");
                    System.out.println("\nNumber " + (i + 1) + ": ");
                    reader.next();
                }
                array[i] = reader.nextInt();
            }while(array[i] <= 0);
        }
        return array;
    }


    public static void printArray(int[] array){
        /**
         * Prints out the completed array. The printed line is built in the
         * printArray string using the for loop to append each number to the
         * string.
         */
        String printArray = "Array = { ";

        for(int i = 0; i < array.length; i++){
            printArray += array[i];
            if(i < array.length - 1)
                printArray += ", ";
        }
        printArray += " }";
        System.out.println("\n" + printArray);
    }


    public static void printArrayLowHigh(int[] array){
        /**
         * This function takes the array and finds the lowest and highest
         * number, then prints these values out.
         */
        int highNumber = array[0];
        int lowNumber = array[0];

        for (int i = 0; i < array.length; i++) {
            if (array[i] < lowNumber)
                lowNumber = array[i];
            if (array[i] > highNumber)
                highNumber = array[i];
        }

        System.out.println("Largest number is: " + highNumber);
        System.out.println("Smallest number is: " + lowNumber);
    }


    // This function is unused, but it is another interesting way to get the
    // low and high numbers.
    public static int findFloorCeiling(String returnType, int[] array) {
        /**
         * Finds and returns the highest or lowest number in the array based on
         * the returnType. If the returnType is floor the lowest number is
         * returned. if the returnType is ceiling then the highest number is
         * returned.
         */
        int number = array[0];

        for (int i = 0; i < array.length; i++) {
            if (returnType == "floor") {
                if (array[i] < number)
                    number = array[i];
                else if (returnType == "ceiling")
                    if (array[i] > number)
                        number = array[i];
            }
        }
        return number;
    }
}