public class BasePlusCommissionEmployee extends CommissionEmployee {

    private double salary;

    public BasePlusCommissionEmployee(String name, String ssn,
            double commissionRate, double grossSales, double salary) {
        super(name, ssn, commissionRate, grossSales);
        if (!validateSalary(salary)) {
            salary = 0;
        }
        this.salary = salary;
    }

    public static boolean validateSalary(double salary) {
        if (salary < 0) {
            return false;
        }
        return true;
    }

    public double getSalary() {
        return salary;
    }

    public double earnings() {
        return (super.earnings() + salary);
    }

    public String toString() {
        return String.format("%s %f", super.toString(), this.earnings());
    }
}
