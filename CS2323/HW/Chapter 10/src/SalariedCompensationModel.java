public class SalariedCompensationModel extends CompensationModel {

    private double weeklySalary;

    public SalariedCompensationModel(double weeklySalary) {
        if (weeklySalary < 0.0) {
            throw new IllegalArgumentException("weeklySalary cannot be less than 0.0.");
        }
        this.weeklySalary = weeklySalary;
    }

    @Override
    public double earnings() {
        return weeklySalary;
    }

}
