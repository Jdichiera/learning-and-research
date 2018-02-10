import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.text.*;

public class DVD extends JFrame implements ActionListener{
    JLabel sortPrompt = new JLabel("Sort by:");
    JComboBox<String> fieldCombo = new JComboBox<>();
    JTextPane textPane = new JTextPane();

    String title[] = {"Casablanca", "Citizen Kane", "Singing in the Rain",
            "The Wizard of Oz"};
    String studio[] = {"Warner Brothers", "RKO Pictures", "MGM", "MGM"};
    String year[] = {"1942", "1941", "1952", "1939"};

    public DVD(){
        super("Classics on DVD");
    }

    public JMenuBar createMenuBar(){
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        JMenu menuFile = new JMenu("File", true);
            menuFile.setMnemonic(KeyEvent.VK_F);
            menuFile.setDisplayedMnemonicIndex(0);
            menuBar.add(menuFile);

        JMenuItem menuFileExit = new JMenuItem("Exit");
            menuFileExit.setMnemonic(KeyEvent.VK_X);
            menuFileExit.setDisplayedMnemonicIndex(1);
            menuFile.add(menuFileExit);
            menuFileExit.setActionCommand("Exit");
            menuFileExit.addActionListener(this);

        JMenu menuEdit = new JMenu("Edit", true);
            menuEdit.setMnemonic(KeyEvent.VK_E);
            menuEdit.setDisplayedMnemonicIndex(0);
            menuBar.add(menuEdit);

        JMenuItem menuEditInsert = new JMenuItem("Insert New DVD");
            menuEditInsert.setMnemonic(KeyEvent.VK_I);
            menuEditInsert.setDisplayedMnemonicIndex(0);
            menuEdit.add(menuEditInsert);
            menuEditInsert.setActionCommand("Insert");
            menuEditInsert.addActionListener(this);

        JMenu menuEditSearch = new JMenu("Search");
            menuEditSearch.setMnemonic(KeyEvent.VK_R);
            menuEditSearch.setDisplayedMnemonicIndex(3);
            menuEdit.add(menuEditSearch);

        JMenuItem menuEditSearchByTitle = new JMenuItem("by Title");
            menuEditSearchByTitle.setMnemonic(KeyEvent.VK_T);
            menuEditSearchByTitle.setDisplayedMnemonicIndex(3);
            menuEditSearch.add(menuEditSearchByTitle);
            menuEditSearchByTitle.setActionCommand("title");
            menuEditSearchByTitle.addActionListener(this);

        JMenuItem menuEditSearchByStudio = new JMenuItem("by Studio");
            menuEditSearchByStudio.setMnemonic(KeyEvent.VK_S);
            menuEditSearchByStudio.setDisplayedMnemonicIndex(3);
            menuEditSearch.add(menuEditSearchByStudio);
            menuEditSearchByStudio.setActionCommand("studio");
            menuEditSearchByStudio.addActionListener(this);

        JMenuItem menuEditSearchByYear = new JMenuItem("by Year");
            menuEditSearchByYear.setMnemonic(KeyEvent.VK_Y);
            menuEditSearchByYear.setDisplayedMnemonicIndex(3);
            menuEditSearch.add(menuEditSearchByYear);
            menuEditSearchByYear.setActionCommand("year");
            menuEditSearchByYear.addActionListener(this);

            return menuBar;
    }

    public Container createContentPane(){
        fieldCombo.addItem("Title");
        fieldCombo.addItem("Studio");
        fieldCombo.addItem("Year");
        fieldCombo.addActionListener(this);
        fieldCombo.setToolTipText("Click the drop-down arrow to display sort " +
                "fields.");

        JPanel northPanel = new JPanel();
            northPanel.setLayout(new FlowLayout());
            northPanel.add(sortPrompt);
            northPanel.add(fieldCombo);

        JPanel centerPanel = new JPanel();
            setTabsAndStyles(textPane);
            textPane = addTextToTextPane();
            JScrollPane scrollPane = new JScrollPane(textPane);
                scrollPane.setVerticalScrollBarPolicy(JScrollPane
                        .VERTICAL_SCROLLBAR_ALWAYS);
                scrollPane.setPreferredSize(new Dimension(500, 200));
            centerPanel.add(scrollPane);

        Container c = getContentPane();
            c.setLayout(new BorderLayout(10,10));
            c.add(northPanel, BorderLayout.NORTH);
            c.add(centerPanel,BorderLayout.CENTER);

        return c;
    }

    protected void setTabsAndStyles(JTextPane textPane){
        TabStop[] tabs = new TabStop[2];
            tabs[0] = new TabStop(200, TabStop.ALIGN_LEFT, TabStop.LEAD_NONE);
            tabs[1] = new TabStop(350, TabStop.ALIGN_LEFT, TabStop.LEAD_NONE);
        TabSet tabset = new TabSet(tabs);

        StyleContext tabStyle = StyleContext.getDefaultStyleContext();
        AttributeSet aset = tabStyle.addAttribute(SimpleAttributeSet.EMPTY,
                StyleConstants.TabSet, tabset);
        textPane.setParagraphAttributes(aset, false);

        Style fontStyle = StyleContext.getDefaultStyleContext().getStyle
                (StyleContext.DEFAULT_STYLE);
        StyleConstants.setFontFamily(fontStyle, "SanSerif");

        Style regular = textPane.addStyle("regular", fontStyle);
        StyleConstants.setFontFamily(fontStyle, "SanSerif");

        Style s = textPane.addStyle("italic", regular);
        StyleConstants.setItalic(s, true);

        s = textPane.addStyle("bold", regular);
        StyleConstants.setBold(s, true);

        s = textPane.addStyle("large", regular);
        StyleConstants.setFontSize(s, 16);
    }


    public JTextPane addTextToTextPane(){
        Document doc = textPane.getDocument();
        try{
            doc.remove(0, doc.getLength());

            doc.insertString(0, "TITLE\tSTUDIO\tYEAR\n", textPane.getStyle
                    ("large"));

            for(int j = 0; j < title.length; j++){
                doc.insertString(doc.getLength(), title[j] + "\t", textPane
                        .getStyle("bold"));
                doc.insertString(doc.getLength(), studio[j] + "\t", textPane
                        .getStyle("italic"));
                doc.insertString(doc.getLength(), year[j] + "\n", textPane
                        .getStyle("regular"));
            }
        }
        catch(BadLocationException ble){
            System.err.println("Couldn't insert text.");
        }
        return textPane;
    }

    public void actionPerformed(ActionEvent e){
        String arg = e.getActionCommand();
        if(e.getSource() == fieldCombo){
            switch(fieldCombo.getSelectedIndex()){
                case 0:
                    sort(title);
                    break;
                case 1:
                    sort(studio);
                    break;
                case 2:
                    sort(year);
                    break;
            }
        }
        if(arg == "Exit")
            System.exit(0);

        if (arg == "Insert") {
            String newTitle = JOptionPane.showInputDialog(null, "Please enter" +
                    " the new movie's title");
            String newStudio = JOptionPane.showInputDialog(null, "Please " +
                    "enter the studio for " + newTitle);
            String newYear = JOptionPane.showInputDialog(null, "Please enter " +
                    "the year for " + newTitle);

            title = enlargeArray(title);
            studio = enlargeArray(studio);
            year = enlargeArray(year);

            title[title.length - 1] = newTitle;
            studio[studio.length - 1] = newStudio;
            year[year.length - 1] = newYear;

            sort(title);
            fieldCombo.setSelectedIndex(0);
        }

        if(arg == "title")
            search(arg, title);
        if(arg == "studio")
            search(arg, studio);
        if(arg == "year")
            search(arg, year);
    }

    public String[] enlargeArray(String[] currentArray){
        String[] newArray = new String[currentArray.length + 1];
        for(int i = 0; i < currentArray.length; i++)
            newArray[i] = currentArray[i];
        return newArray;
    }

    public void sort(String tempArray[]){
        for(int pass = 1; pass < tempArray.length; pass++){
            for(int element = 0; element < tempArray.length - 1; element++){
                if(tempArray[element].compareTo(tempArray[element + 1]) > 0){
                    swap(title, element, element + 1);
                    swap(studio, element, element + 1);
                    swap(year, element, element + 1);
                }
            }
            addTextToTextPane();
        }
    }

    public void swap(String swapArray[], int first, int second){
        String hold;
        hold = swapArray[first];
        swapArray[first] = swapArray[second];
        swapArray[second] = hold;
    }

    public void search(String searchField, String searchArray[]){
        try{
            Document doc = textPane.getDocument();
            doc.remove(0, doc.getLength());

            doc.insertString(0, "TITLE\tSTUDIO\tYEAR\n", textPane.getStyle
                    ("large"));

            String search = JOptionPane.showInputDialog(null, "Please enter " +
                    "the " + searchField);
            boolean found = false;

            for(int i = 0; i < title.length; i++){
                if(search.compareTo(searchArray[i]) == 0){
                    doc.insertString(doc.getLength(), title[i] + "\t",
                            textPane.getStyle("bold"));
                    doc.insertString(doc.getLength(), studio[i] + "\t",
                            textPane.getStyle("italic"));
                    doc.insertString(doc.getLength(), year[i] + "\t",
                            textPane.getStyle("regular"));
                    found = true;
                }
            }
            if(found == false){
                JOptionPane.showMessageDialog(null, "Your search produced no " +
                        "results.", "No results found", JOptionPane
                        .INFORMATION_MESSAGE);
                sort(title);
            }
        }
        catch(BadLocationException ble){
            System.err.println("Couldnt insert text.");
        }
    }

    public static void main(String args[]){
        JFrame.setDefaultLookAndFeelDecorated(true);
        DVD f = new DVD();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setJMenuBar(f.createMenuBar());
        f.setContentPane(f.createContentPane());
        f.setSize(600, 375);
        f.setVisible(true);
    }

}