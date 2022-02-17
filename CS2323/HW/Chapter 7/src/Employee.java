public class Employee {
    private double commissionTotal;
    public static int[] counters = new int[9];

    public Employee(double commissionTotal) {
        this.commissionTotal = commissionTotal;
    }

    public double getCommissionTotal() {
        return commissionTotal;
    }
}
