public class BasePlusCommissionEmployee extends CommissionEmployee {

    private double salary;

    public BasePlusCommissionEmployee(String name, String ssn,
            double grossSales, double commissionRate, double salary) {
        super(name, ssn, grossSales, commissionRate);
        this.salary = salary;
    }

    public BasePlusCommissionEmployee(String name, String ssn) {
        super(name, ssn);
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double earnings() {
        return super.earnings() + salary;
    }

}
