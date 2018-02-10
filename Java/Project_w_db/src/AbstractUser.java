public abstract class AbstractUser {
    String userID;
    String firstName;
    String lastName;
    String password;
    int admin;

    public AbstractUser(String newUserId, String newFirstName, String newLastName,
                String newPassword){
        userID = newUserId;
        firstName = newFirstName;
        lastName = newLastName;
        password = newPassword;
    }

    public String getUserID() {
        return userID;
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    abstract void printUserType();

}
