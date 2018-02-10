












import javax.swing.JOptionPane;
public class BodyMassSwing {
    public static void main(String[] args){
        String height, weight;
        int inches, pounds;
        double kilograms, meters, index;

        // Prints prompts and gets input
        System.out.println("\tBody Mass Index Calculator");
        height = JOptionPane.showInputDialog(null, "Enter your height to " +
                "the nearest inch: ");
            inches = Integer.parseInt(height);
        weight = JOptionPane.showInputDialog(null, "Enter yout weight to " +
                "the nearest pound: ");
        pounds = Integer.parseInt(weight);

        // Calculation
        meters = inches / 39.36;
        kilograms = pounds / 2.2;
        index = kilograms / Math.pow(meters, 2);

        // Output
        JOptionPane.showMessageDialog(null, "Your BMI is " + Math.round
                (index) + ".", "Body Mass Calculator", JOptionPane
                .PLAIN_MESSAGE);
        System.exit(0);
    }
}
