public class User {
    public int id;
    public String firstName;
    public String lastName;
    public String password;
    public boolean isAdmin;

    User(int newId, String newFirstName, String newLastName, String
            newPassword, boolean admin){
        id = newId;
        firstName = newFirstName;
        lastName = newLastName;
        password = newPassword;
        isAdmin = admin;
    }

    public int getId(){return id;};
    public String getFirstName(){return firstName;}
    public String getLastName(){return lastName;}
    public String getPassword(){return password;}
    public boolean getAdminStatus(){return isAdmin;}
}