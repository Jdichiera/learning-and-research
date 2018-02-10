












import java.io.*;
public class BodyMass {
    public static void main(String[] args) throws IOException {
        String height, weight;
        int inches, pounds;
        double kilograms, meters, index;

        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));

        // Prints prompts and gets input
        System.out.println("\tBody Mass Index Calculator");
        System.out.println();
        System.out.println("\t\tEnter your height to the nearest inch: ");
            height = dataIn.readLine();
            inches = Integer.parseInt(height);
        System.out.println("\t\tEnter your weight to the nearest pound: ");
            weight = dataIn.readLine();
            pounds = Integer.parseInt(weight);

        // Calculation
        meters = inches / 39.36;
        kilograms = pounds / 2.2;
        index = kilograms / Math.pow(meters, 2);

        // Output
        System.out.println();
        System.out.println("\tYour BMI is " + Math.round(index) + ".");
        System.out.println();
    }
}
