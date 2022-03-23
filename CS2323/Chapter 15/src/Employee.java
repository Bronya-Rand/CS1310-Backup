public abstract class Employee {

    private String name;
    private String ssn;

    public Employee(String name, String ssn) {
        this.name = name;
        this.ssn = ssn;
    }

    public String toString() {
        return String.format("%s %s %f%n", name, ssn, earnings());
    }

    public abstract double earnings();
}
