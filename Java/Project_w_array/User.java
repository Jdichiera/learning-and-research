public abstract class User {
    int userId;
    String firstName;
    String lastName;
    String password;
    //boolean isAdministrator;

    public User(int newUserId, String newFirstName, String newLastName, String
            newPassword){
        userId = newUserId;
        firstName = newFirstName;
        lastName = newLastName;
        password = newPassword;
    }

    public int getUserId() {
        return userId;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }


    public void setFirstName(String newFirstName){
        firstName = newFirstName;
    }

    public void setLastName(String newLastName){
        lastName = newLastName;
    }

    public void setPassword(String newPassword){
        password = newPassword;
    }

    //public boolean setIsAdministrator(boolean newAdminStatus){
    //    isAdministrator = newAdminStatus;
    //}

    abstract void printUserType();

}