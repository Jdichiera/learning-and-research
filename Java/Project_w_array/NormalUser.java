public class NormalUser extends scratchpad.asda.User {
    boolean isAdministrator;
    public NormalUser(int newUserId, String newFirstName, String newLastName,
                   String newPassword){
        super(newUserId, newFirstName, newLastName, newPassword);
        isAdministrator = false;
    }
    public boolean getIsAdministrator() {
        return isAdministrator;
    }

    void printUserType(){
        System.out.println("--==NORMAL USER==--");
    }
}