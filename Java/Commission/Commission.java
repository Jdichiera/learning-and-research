








import javax.swing.JOptionPane;
import java.text.DecimalFormat;

public class Commission{
    public static void main(String[] args){
        // Variables
        double dollars, answer;
        int empCode;

        dollars = getSales();
        empCode = getCode();
        answer = getComm(dollars, empCode);
        output(answer, dollars);
        finish();
    }

    // Gets the sales amount from the user
    public static double getSales(){
        double sales = 0.0;
        boolean done = false;

        // Loop while not done
        while(!done) {
            String answer = JOptionPane.showInputDialog(null, "Enter the " +
                    "sales amount\n(do not use commas or dollar " +
                    "signs)\n or click Cancel to exit: ");
            if (answer == null) finish();
            try {
                sales = Double.parseDouble(answer);
                if (sales <= 0) throw new NumberFormatException();
                else done = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Your entry was not in " +
                        "the proper format.", "Error", JOptionPane
                        .INFORMATION_MESSAGE);
            }
        }
        return sales;
    }

    // Gets the sales code
    public static int getCode(){
        int code = 0;
        boolean done = false;

        while(!done){
            try{
                String message = "Enter the commission code: \n\n1) telephone" +
                        " Sales \n2) In-Store Sales \n3) Outside Sales\n\n";
                code = Integer.parseInt(JOptionPane.showInputDialog(null,
                        message));

                // Test for valid code 1, 2 or 3
                if(code < 1 || code > 3) throw new NumberFormatException();
                else done = true;
            }
            catch (NumberFormatException e){
                JOptionPane.showMessageDialog(null, "Please enter a 1, 2, or " +
                        "3.", "Error", JOptionPane.INFORMATION_MESSAGE);
            }
        }
        return code;
    }

    // Takes the dollars and empCode and returns the correct commission
    public static double getComm(double employeeSales, int employeeCode){
        double commission = 0.0;

        switch(employeeCode){
            case 1:
                commission = .10 * employeeSales;
                break;
            case 2:
                commission = .14 * employeeSales;
                break;
            case 3:
                commission = .18 * employeeSales;
                break;
        }
        return commission;
    }

    // Displays the commissions and sales.
    public static void output(double commission, double sales){
        DecimalFormat twoDigits = new DecimalFormat("$#,000.00");

        JOptionPane.showMessageDialog(null, "Your commission on sales of " +
                twoDigits.format(sales) + " is " + twoDigits.format
                (commission), "Commission Totals", JOptionPane
                .INFORMATION_MESSAGE);
    }





    // Ends the program
    public static void finish(){
        System.exit(0);
    }
}