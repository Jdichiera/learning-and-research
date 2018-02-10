/**
 * This program allows a user to input 10 clients and outputs the
 * information into a sequential file. Then the file will be read and the
 * information will be displayed to the screen in the following format:
 * ID#; First Name; Last Name; Account Balance.
 */

import java.io.*;
import java.util.*;
import java.util.Scanner;

public class SequentialFileOutput{

    static final String FILENAME = "file.txt";

    public static void main(String args[]){

        displayMenu();

    }
    public static void addContent(String[] array){
        Scanner scanner = new Scanner(System.in);
        boolean append = false;
        boolean token = true;

        System.out.println("Write content in append mode? (Y/N)");
        String input = scanner.nextLine().toLowerCase();

        while ( token ){
            if(input.equals("y")){
                append = true;
                token = false;
            } else if (input.equals("n")){
                append = false;
                token = false;
            } else {
                System.out.println("Please enter Y or N ... ");
                input = scanner.nextLine().toLowerCase();
                System.out.println("2 " + input);
            }
        }

        writeToFile(array, append);
    }


    public static void readFile(){
        System.out.println("\n\n\t--== Read File ==--");
        System.out.println("Attempting to read file ... ");
        List<String> records = new ArrayList<>();
        FileReader fReader = null;
        BufferedReader fBuffer = null;

        try {

            fReader = new FileReader(FILENAME);
            fBuffer = new BufferedReader(fReader);

            String line;
            while ((line = fBuffer.readLine()) != null){
                records.add(line);
            }

            System.out.println("File read. \nProcessed " + records.size() +
                    " lines.");
            printRecords(records);

        } catch (Exception e) {
            System.out.println("Unable to read file : "
                    + e.getMessage());
        } finally {
            try {
                if (fBuffer != null){
                    fBuffer.close();
                }
                if (fReader != null){
                    fReader.close();
                }

            } catch (Exception e) {
                System.out.println("Unable to close reader : "
                        + e.getMessage());
            }
        }
        displayMenu();
    }

    public static void printRecords(List<String> records){
        String delimiter = ";";
        System.out.println("\n\n\t__Contents of " + FILENAME + "__");
        System.out.println("Attempting to write to file ... ");

        for (String record : records){
            String[] splitRecord = record.split(delimiter);
            System.out.print("ID#: " + splitRecord[0] + " |_");
            System.out.print("| First Name: " + splitRecord[1]+ " |_");
            System.out.print("| Last Name: " + splitRecord[2]+ " |_");
            System.out.print("| Account Balance: " + splitRecord[3] + "\n");
        }
        displayMenu();
    }

    public static void writeToFile(String[] contentArray, boolean append){


        File file = new File(FILENAME);
        FileWriter fWriter = null;
        BufferedWriter fBuffer = null;
        System.out.println("\n\n\t--== Write to File ==--");
        System.out.println("Attempting to write to file ... ");



        try {
            if (!file.exists()){
                file.createNewFile();
            }

            fWriter = new FileWriter(file, append);
            fBuffer = new BufferedWriter(fWriter);

            for (int i = 0; i < 10; i++){
                fBuffer.write(contentArray[i]);
                System.out.println(contentArray[i]);
            }
            System.out.println("File write complete.");

        } catch (Exception e) {
            System.out.println("Unable to write to file : " + e.getMessage());

        } finally {
            try {
                if (fBuffer != null){
                    fBuffer.close();
                }
                if (fWriter != null){
                    fWriter.close();
                }

            } catch(Exception e) {
                System.out.println("Unable to close writer : "
                        + e.getMessage());
            }
        }
        displayMenu();
    }


    public static void displayMenu()
    {
        System.out.println("\n\n\t--== Main Menu ==--");
        System.out.println("1. Read File");
        System.out.println("2. Write to File");
        System.out.println("3. Quit");

        Scanner reader = new Scanner(System.in);
        int menuSelection = reader.nextInt();

        String contactArray[];

        switch(menuSelection)
        {
            case 1:
                readFile();
                break;
            case 2:
                contactArray = fillArray();
                addContent(contactArray);
                break;
            case 3:
                exit();
                break;
        }
    }

    public static String[] fillArray(){

        Scanner reader = new Scanner(System.in);
        String contactArray[] = new String[10];

        System.out.println("Please enter contact information for 10 people.");

        String contact = "";

        for(int i = 0; i < 10; i++){
            System.out.println("\nContact ID: ");
            contact += reader.nextLine() + ";";
            System.out.println("\nFirst Name: ");
            contact += reader.nextLine() + ";";
            System.out.println("\nLast Name: ");
            contact += reader.nextLine() + ";";
            System.out.println("\nAccount Balance: ");
            contact += reader.nextLine() + System.lineSeparator();

            contactArray[i] = contact;
            contact = "";
        }
        return contactArray;
    }

    public static void exit()
    {
        System.out.println("__Exiting Program__");
        System.exit(0);

    }
}