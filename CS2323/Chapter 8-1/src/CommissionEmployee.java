public class CommissionEmployee {

    private String name;
    private String ssn;
    private double grossSale;
    private double commissionRate;

    public CommissionEmployee(String name, String ssn, double grossSale,
            double commissionRate) {
        this.name = name;
        this.ssn = ssn;
        this.grossSale = grossSale;
        if (commissionRate < 0) {
            commissionRate = 0;
        }
        this.commissionRate = commissionRate;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSSN(String ssn) {
        this.ssn = ssn;
    }

    public void setGrossRate(double grossSale) {
        this.grossSale = grossSale;
    }

    public void setCommissionRate(double commissionRate) {
        if (commissionRate < 0) {
            commissionRate = 0;
        }
        this.commissionRate = commissionRate;
    }

    public String getName() {
        return name;
    }

    public String getSSN() {
        return ssn;
    }

    public double getGrossSale() {
        return grossSale;
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public double earnings() {
        return commissionRate * grossSale;
    }

    public String toString() {
        return String.format("%s %s; %s: %f", this.name, this.ssn, "earnings",
                this.earnings());
    }
}
