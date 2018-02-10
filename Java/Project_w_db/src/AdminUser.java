/**
 * Created by udichje on 5/7/17.
 */
public class AdminUser extends AbstractUser{
    int admin;

    public AdminUser(String newUserId, String newFirstName, String newLastName,
                     String newPassword, int admin){
        super(newUserId, newFirstName, newLastName, newPassword);
        admin = admin;
    }

    public int getIsAdmin() {
        return admin;
    }

    public void setAdmin(int admin) {
        this.admin = admin;
    }

    public void printUserType(){
        System.out.println("Admin user");
    }
}
