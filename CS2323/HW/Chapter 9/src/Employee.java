public class Employee {
    
    private String firstName;
    private String lastName;
    private String ssn;
    
    Employee(String firstName, String lastName, String ssn) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.ssn = ssn;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getSSN() {
        return ssn;
    }

    public String toString() {
        return String.format("%s: %s %s%n%s: %s%n", "commission employee", getFirstName(), getLastName(), "social security number", getSSN());
    }
}
