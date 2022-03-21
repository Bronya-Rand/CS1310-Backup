public class EmployeeComposition {

    private String firstName;
    private String lastName;
    private String ssn;
    private CompensationModel compModel;

    public EmployeeComposition(String firstName, String lastName, String ssn, CompensationModel compModel) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.ssn = ssn;
        this.compModel = compModel;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setSSN(String ssn) {
        this.ssn = ssn;
    }

    public void setCompensationModel(CompensationModel compModel) {
        this.compModel = compModel;
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

    public double earnings() {
        return compModel.earnings();
    }
}
