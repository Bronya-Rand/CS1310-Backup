public class CommissionEmployee extends Employee {

    private double grossSales;
    private double commissionRate;

    public CommissionEmployee(String name, String ssn, double grossSales, double commissionRate) {
        super(name, ssn);
        // assume input is valid
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
    }

    @Override
    public double earnings() {
        // TODO Auto-generated method stub
        return grossSales * commissionRate;
    }
}
