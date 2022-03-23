public class EmployeeFactoryClass {

    public Employee EmployeeFactory(String employeeType, String name,
            String ssn) {
        switch (employeeType) {
        case "1":
            return new CommissionEmployee(name, ssn);
        case "2":
            return new BasePlusCommissionEmployee(name, ssn);
        default:
            throw new IllegalArgumentException(
                    "We don't have that kind of employee");
        }
    }
}
