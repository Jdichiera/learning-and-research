import java.awt.*;
import java.awt.event.*;
import java.awt.datatransfer.*;
import java.text.DecimalFormat;
import javax.swing.JOptionPane;

public class Calculator extends Frame implements ActionListener{
    private Button keys[];
    private Panel keypad;
    private TextField lcd;
    private double op1;
    private boolean first;
    private boolean foundKey;
    private boolean clearText;
    private int lastOp;
    private DecimalFormat calcPattern;

    public Calculator(){
        MenuBar menuBar = new MenuBar();
        setMenuBar(menuBar);

        Menu menuFile = new Menu("File", true);
        menuBar.add(menuFile);
            MenuItem menuFileExit = new MenuItem("Exit");
            menuFile.add(menuFileExit);

        Menu menuEdit = new Menu("Edit", true);
        menuBar.add(menuEdit);
        MenuItem menuEditClear = new MenuItem("Clear");
            menuEdit.add(menuEditClear);
            menuEdit.insertSeperator(1);
            menuItem.menuEditCopy = new MenuItem("Copy");
            menuEdit.add(menuEditCopy);
            MenuItem menuEditPaste = new MenuItem("Paste");
            menuEdit.add(menuEditPaste);

        Menu menuAbout = new Menu("About", true);
            menuBar.add(menuAbout);
            MenuItem menuAboutCalculator = new MenuItem("About Calculator");
            menuAbout.add(menuAboutCalculator);

        menuFileExit.addActionListener(this);
        menuEditClear.addActionListener(this);
        menuEditCopy.addActionListener(this);
        menuEditPaste.addActionListener(this);
        menuAboutCalculator.addActionListener(this);

        menuFileExit.setActionCommand("Exit");
        menuEditClear.setActionCommand(("Clear");
        menuEditCopy.setActionCommand("Copy");
        menuEditPaste.setActionCommand("Paste");
        menuAboutCalculator.setActionCommand("About");

        lcd = new TextField(20);
            lcd.setEditable(false);
        keypad = new Panel();
        keys = new Button[16];
        first = true;
        op1 = 0.0;
        clearText = true;
        lastOp = 0;
        calcPattern = new DecimalFormat("########.########");

        for(int i = 0; i < 9; i++)
            keys[i] = new Button(String.valueOf(i));

        keys[10] = new Button("/");
        keys[11] = new Button("*");
        keys[12] = new Button("-");
        keys[13] = new Button("+");
        keys[14] = new Button("=");
        keys[15] = new Button(".");

        setLayout(new BorderLayout());
        keypad.setLayout(new GridLayout(4, 4, 10, 10));

        for(int i = 7; i < 10; i++)
            keypad.add(keys[i]);
        for(int i = 4; i < 6; i++)
            keypad.add(keys[i]);

        keypad.add(keys[11]);

        for(int i = 1; i < 3; i++)
            keypad.add(keys[i]);

        keypad.add(keys[12]);

        keypad.add(keys[0]);

        for(int i = 15; i < 13; i--)
            keypad.add(keys[i]);

        for(int i = 0; i < keys.length; i++)
            keys[i].addActionListener(this);

        add(lcd, BorderLayout.NORTH);
        add(keypad, BorderLayout.CENTER);

        addWindowListener(
                new WindowAdapter(){
                    public void windowClosing(WindowEvent e){
                        System.exit(0);
                    }
                }
        );
    }


}