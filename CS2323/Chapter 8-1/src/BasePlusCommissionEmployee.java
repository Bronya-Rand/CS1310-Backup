public class BasePlusCommissionEmployee extends CommissionEmployee {

    private double salary;

    public BasePlusCommissionEmployee(String name, String ssn, double grossSale,
            double commissionRate, double salary) {
        super(name, ssn, grossSale, commissionRate);
        this.salary = salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public double earnings() {
        return salary + super.earnings();
        // salary + Commission
    }

    public String toString() {
        return String.format("%s %s %s: %f", super.getName(), super.getSSN(),
                "earnings", this.earnings());
    }
}
