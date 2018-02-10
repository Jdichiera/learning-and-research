/**
 * Created by udichje on 4/4/17.
 */
import java.util.Scanner;
import java.util.Arrays;
public class Reverse {
    public static void main(String[] args){
        int[] numberArray = GetInput();
        //System.out.println("You entered: " + Arrays.toString(numberArray));

        ReverseThenPrintString(numberArray);
        PrintReverse(numberArray);
        ManuallyReverseArray(numberArray);
    }


    // Get input from the user and then return the number input
    public static int[] GetInput(){
        System.out.println("\n\nThis program will allow you to enter a set of numbers, then " +
                "the program will print out the numbers entered, in reverse.");
        System.out.print("How many numbers would you like to add? ");
        Scanner input = new Scanner(System.in);
        int count = input.nextInt();//Integer.parseInt(input.next());
        int numberArray[] = new int[count];
        System.out.println("Please enter " + count + " numbers:");
        for(int i = 0; i < count; i++){
            System.out.print("Number " + (i + 1) + ": ");
            numberArray[i] = input.nextInt(); //Integer.parseInt(input.next());
        }
        return numberArray;
    }


    // Reverse the array into a new string variable and then print it out.
    public static void ReverseThenPrintString(int[] numberArray){
        String reversedString = "";
        int count = numberArray.length;
        for(int i = count; i > 0; i--){
            reversedString += numberArray[i - 1] + ", ";
        }
        System.out.println("\nSaving the reversed array into a string and printing it out: ");
        System.out.println(reversedString);
    }


    // Instead of reversing the array, print out the numbers from the end of the array to
    // the beginning.
    public static void PrintReverse(int[] numberArray){
        int count = numberArray.length;
        System.out.println("\nPrinting the array from last number to first: ");
        for(int i = count; i > 0; i--){
            System.out.print(numberArray[i - 1] + ", ");
        }
    }


    //Manually reverse the array into a new array and then print it out
    public static void ManuallyReverseArray(int[] numberArray) {
        int count = numberArray.length;
        int[] newArray = new int[count];

        for (int i = 0; i < count; i++) {
            newArray[i] = numberArray[(count - 1) - i];
        }
        System.out.println("\n\nReading the array from last to first into a new array and printing it out: ");
        System.out.println(Arrays.toString((newArray)));
    }
}