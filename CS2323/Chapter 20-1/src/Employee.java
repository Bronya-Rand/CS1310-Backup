public class Employee implements Comparable<Employee> {
    private String name;
    private String ssn;
    private double earnings;

    public Employee(String name, String ssn, double earnings) {
        this.name = name;
        this.ssn = ssn;
        this.earnings = earnings;
    }

    @Override
    public int compareTo(Employee emp) {
        if (this.earnings > emp.earnings) {
            return 1;
        }
        if (this.earnings == emp.earnings) {
            return 0;
        }
        return -1;
    }

    public String toString() {
        return String.format("%s %s %f", name, ssn, earnings);
    }
}
