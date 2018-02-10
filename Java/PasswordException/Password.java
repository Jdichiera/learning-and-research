import java.util.*;

public class Password{
    final static int MIN_SIZE = 6;
    final static int MAX_SIZE = 15;
    static int maxHistory = 4;
    static int expiresNotifyLimit = 3;

    private int maxUses = 120;
    private int remainingUses = maxUses;
    private boolean autoExpires = true;
    private boolean expired = false;

    private ArrayList passwordHistory;

    public Password(String newPassword) throws PasswordException{
        passwordHistory = new ArrayList(maxHistory);
        set(newPassword);
    }

    public Password(String newPassword, int numMaxUses) throws
            PasswordException{
        passwordHistory = new ArrayList(maxHistory);
        maxUses = numMaxUses;
        remainingUses = numMaxUses;
        set(newPassword);
    }

    public Password(String newPassword, boolean passwordAutoExpires) throws
            PasswordException{
        passwordHistory = new ArrayList(maxHistory);
        autoExpires = passwordAutoExpires;
        set(newPassword);
    }
}