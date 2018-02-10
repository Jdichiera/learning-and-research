public class PasswordSizeException extends PasswordInvalidFormatException{
    private int passwordSize;
    private int minSize;
    private int maxSize;

    public PasswordSizeException(String msg, int passwordSize, int minSize,
                                 int maxSize){
        super(msg);
        this.passwordSize = passwordSize;
        this.minSize = minSize;
        this.maxSize = maxSize;
    }

    public int getPasswordSize(){
        return passwordSize;
    }

    public int getMinSize(){
        return minSize;
    }

    public int getMaxSize(){
        return maxSize;
    }
}