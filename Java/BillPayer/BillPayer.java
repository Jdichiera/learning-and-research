import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.text.*;
import java.util.*;

public class BillPayer extends JFrame implements ActionListener{
    //Declare output stream
    DataOutputStream output;

    JPanel firstRow = new JPanel();
    JPanel secondRow = new JPanel();
    JPanel thirdRow = new JPanel();
    JPanel fourthRow = new JPanel();
    JPanel fifthRow = new JPanel();
    JPanel sixthRow = new JPanel();
    JPanel seventhRow = new JPanel();
    JPanel eighthRow = new JPanel();

    JPanel fieldPanel = new JPanel();
    JPanel buttonPanel = new JPanel();

    JLabel accountNumLabel = new JLabel("Account " +
            "Number:\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        JTextField accountNum = new JTextField(15);
    JLabel paymentLabel = new JLabel("Payment Amount:");
        JTextField payment = new JTextField(10);
    JLabel firstNameLabel = new JLabel("First " +
            "Name:\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        JTextField firstName = new JTextField(10);
    JLabel lastNameLabel = new JLabel("Last Name:");
        JTextField lastName = new JTextField(20);
    JLabel addressLabel = new JLabel("Address:");
        JTextField address = new JTextField(35);
    JLabel cityLabel = new JLabel
            ("City\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        JTextField city = new JTextField(10);
    JLabel stateLabel = new JLabel("State:\t\t");
        JTextField state = new JTextField(2);
    JLabel zipLabel = new JLabel("Zip:");
        JTextField zip = new JTextField(9);

    JButton submitButton = new JButton("Submit");



    public static void main(String args[]){
        try{
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif" +
                    ".MotifLookAndFeel");
        }
        catch(Exception e){
            JOptionPane.showMessageDialog(null, "The UIManager could not set " +
                    "the Look and Feel for this application.", "Error",
                    JOptionPane.INFORMATION_MESSAGE);
        }

        BillPayer f = new BillPayer();
        f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        f.setSize(450, 300);
        f.setTitle("Crandall Power and Light Customer Payments");
        f.setResizable(false);
        f.setLocation(200, 200);
        f.setVisible(true);
    }


    public BillPayer(){
        Container c = getContentPane();
        c.setLayout((new BorderLayout()));
        fieldPanel.setLayout(new GridLayout(8, 1));
        FlowLayout rowSetup = new FlowLayout(FlowLayout.LEFT, 5, 3);
            firstRow.setLayout(rowSetup);
            secondRow.setLayout(rowSetup);
            thirdRow.setLayout(rowSetup);
            fourthRow.setLayout(rowSetup);
            fifthRow.setLayout(rowSetup);
            sixthRow.setLayout(rowSetup);
            seventhRow.setLayout(rowSetup);
            eighthRow.setLayout(rowSetup);
        buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER));

        firstRow.add(accountNumLabel);
        firstRow.add(paymentLabel);

        secondRow.add(accountNum);
        secondRow.add(payment);

        thirdRow.add(firstNameLabel);
        thirdRow.add(lastNameLabel);

        fourthRow.add(firstName);
        fourthRow.add(lastName);

        fifthRow.add(addressLabel);

        sixthRow.add(address);

        seventhRow.add(cityLabel);
        seventhRow.add(stateLabel);
        seventhRow.add(zipLabel);

        eighthRow.add(city);
        eighthRow.add(state);
        eighthRow.add(zip);

        fieldPanel.add(firstRow);
        fieldPanel.add(secondRow);
        fieldPanel.add(thirdRow);
        fieldPanel.add(fourthRow);
        fieldPanel.add(fifthRow);
        fieldPanel.add(sixthRow);
        fieldPanel.add(seventhRow);
        fieldPanel.add(eighthRow);

        buttonPanel.add(submitButton);

        c.add(fieldPanel, BorderLayout.CENTER);
        c.add(buttonPanel, BorderLayout.SOUTH);

        submitButton.addActionListener(this);

        Date today = new Date();
        SimpleDateFormat myFormat = new SimpleDateFormat("MMddyyyy");
        String filename = "payments" + myFormat.format(today);

        try{
            output = new DataOutputStream(new FileOutputStream(filename));
        }
        catch(IOException io){
            JOptionPane.showMessageDialog(null, "The program could not create a " +
                    "storage location. Please check the disk drive and then run " +
                    "the prohram again.", "Error", JOptionPane.INFORMATION_MESSAGE);
            System.exit(1);
        }

        addWindowListener(
                new WindowAdapter(){
                    public void windowClosing(WindowEvent e){
                        int answer = JOptionPane.showConfirmDialog(null, "Are " +
                                        "you sure you want to exit and submit the file?",
                                "File Submission", JOptionPane.YES_NO_OPTION);
                        if(answer == JOptionPane.YES_OPTION)
                            System.exit(0);
                    }
                }
        );

    }


    public void actionPerformed(ActionEvent e){
        String arg = e.getActionCommand();
        if(checkFields()){
            try{
                output.writeUTF(accountNum.getText());
                output.writeUTF(payment.getText());
                output.writeUTF(firstName.getText());
                output.writeUTF(lastName.getText());
                output.writeUTF(address.getText());
                output.writeUTF(city.getText());
                output.writeUTF(state.getText());
                output.writeUTF(zip.getText());

                JOptionPane.showMessageDialog(null, "The payment " +
                        "information has been saved.", "Submission " +
                        "Successful", JOptionPane.INFORMATION_MESSAGE);
            }
            catch(IOException c){
                System.exit(1);
            }
            clearFields();
        }
    }


    public boolean checkFields(){
        if((accountNum.getText().compareTo("") < 1)     ||
                (payment.getText().compareTo("") < 1)   ||
                (firstName.getText().compareTo("") < 1) ||
                (lastName.getText().compareTo("") < 1)  ||
                (address.getText().compareTo("") < 1)   ||
                (city.getText().compareTo("") < 1)      ||
                (state.getText().compareTo("") < 1)     ||
                (zip.getText().compareTo("") < 1)){
            JOptionPane.showMessageDialog(null, "You must complete all " +
                    "fields.", "Data Entry Error", JOptionPane.WARNING_MESSAGE);
            return false;
        }
        else{
            return true;
        }
    }

    public void clearFields(){
        accountNum.setText("");
        payment.setText("");
        firstName.setText("");
        lastName.setText("");
        address.setText("");
        city.setText("");
        state.setText("");
        zip.setText("");
        accountNum.requestFocus();
    }



}