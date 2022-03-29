public class BasePlusCommissionCompensationModel extends CompensationModel {

    private double grossSales;
    private double commissionRate;
    private double baseSalary;

    public BasePlusCommissionCompensationModel(double grossSales, double commissionRate, double baseSalary) {
        if (grossSales < 0.0) {
            throw new IllegalArgumentException("Invalid Gross Sales");
        } else if (commissionRate < 0.0) {
            throw new IllegalArgumentException("Invalid Commission Rate");
        } else if (baseSalary < 0.0) {
            throw new IllegalArgumentException("Invalid Base Salary");
        }
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
        this.baseSalary = baseSalary;
    }

    @Override
    public double earnings() {
        // TODO Auto-generated method stub
        return baseSalary + (grossSales * commissionRate);
    }

}
