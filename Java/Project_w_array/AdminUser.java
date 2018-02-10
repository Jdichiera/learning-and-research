public class AdminUser extends scratchpad.asda.User {
    boolean isAdministrator = true;
    public AdminUser(int newUserId, String newFirstName, String newLastName,
                      String newPassword){
        super(newUserId, newFirstName, newLastName, newPassword);
        isAdministrator = true;
    }
    public boolean getIsAdministrator() {
        return isAdministrator;
    }
    public void printUserType(){
        System.out.println("--==ADMIN USER==--");
    }
}