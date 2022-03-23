public class CommissionEmployee extends Employee {

    private double grossSales;
    private double commissionRate;

    public CommissionEmployee(String name, String ssn, double grossSales,
            double commissionRate) {
        super(name, ssn);
        // assume input is valid
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
    }

    public CommissionEmployee(String name, String ssn) {
        super(name, ssn);
    }

    public void set(double commissionRate) {
        this.commissionRate = commissionRate;
    }

    public void setGrossSales(double grossSales) {
        this.grossSales = grossSales;
    }

    @Override
    public double earnings() {
        // TODO Auto-generated method stub
        return grossSales * commissionRate;
    }

}
