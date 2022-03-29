public class HourlyCompensationModel extends CompensationModel {

    private double wage;
    private double hours;

    public HourlyCompensationModel(double wage, double hours) {
        if (wage < 0.0) {
            throw new IllegalArgumentException("wage cannot be less than 0.0.");
        }
        if (hours < 0.0) {
            throw new IllegalArgumentException("hours cannot be less than 0.0.");
        }
        this.wage = wage;
        this.hours = hours;
    }

    @Override
    public double earnings() {
        return wage * hours;
    }
}
