public abstract class Employee implements Payable {

    private String name;
    private String ssn;

    public Employee(String name, String ssn) {
        this.name = name;
        this.ssn = ssn;
    }

    public String toString() {
        return String.format("%s %s", name, ssn);
    }

    public abstract double earnings();

    @Override
    public double getPayableAmount() {
        // TODO Auto-generated method stub
        return earnings();
    }

}
