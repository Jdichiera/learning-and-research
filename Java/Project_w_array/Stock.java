public class Stock{
    String symbol;
    String description;

    public Stock(String newSymbol, String newDescription){
        symbol = newSymbol;
        description = newDescription;
    }

    public String getSymbol(){
        return symbol;
    }

    public String getDescription(){
        return description;
    }
}