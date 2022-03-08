public class CommissionEmployee extends Employee {

    private double commissionRate;
    private double grossSales;

    public CommissionEmployee(String name, String ssn, double commissionRate,
            double grossSales) {
        super(name, ssn);
        if (!validateCommissionRate(commissionRate)) {
            commissionRate = 0;
        }
        if (!validateGrossSales(grossSales)) {
            grossSales = 0;
        }
        this.commissionRate = commissionRate;
        this.grossSales = grossSales;
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public double getGrossSales() {
        return grossSales;
    }

    public void setCommissionRate(double commissionRate) {
        if (!validateCommissionRate(commissionRate)) {
            commissionRate = 0;
        }
        this.commissionRate = commissionRate;
    }

    public void setGrossSales(double grossSales) {
        if (!validateGrossSales(grossSales)) {
            grossSales = 0;
        }
        this.grossSales = grossSales;
    }

    @Override
    public double earnings() {
        return grossSales * commissionRate;
    }

    public static boolean validateCommissionRate(double commissionRate) {
        if (commissionRate > 0) {
            return true;
        }
        return false;
    }

    public static boolean validateGrossSales(double grossSales) {
        if (grossSales > 0) {
            return true;
        }
        return false;
    }

    public String toString() {
        return String.format("%s %f", super.toString(), this.earnings());
    }
}
