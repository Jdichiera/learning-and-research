
public class User extends AbstractUser{
    int admin;

    public User(String newUserId, String newFirstName, String newLastName,
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
        System.out.println("Normal user");
    }
}
