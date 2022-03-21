public class CommissionCompensationModel extends CompensationModel {

    private double grossSales;
    private double commissionRate;

    public CommissionCompensationModel(double grossSales, double commissionRate) {
        if (grossSales < 0.0) {
            throw new IllegalArgumentException("Invalid Gross Sales");
        } else if (commissionRate < 0.0) {
            throw new IllegalArgumentException("Invalid Commission Rate");
        }
        this.grossSales = grossSales;
        this.commissionRate = commissionRate;
    }

    @Override
    public double earnings() {
        // TODO Auto-generated method stub
        return grossSales * commissionRate;
    }

}
