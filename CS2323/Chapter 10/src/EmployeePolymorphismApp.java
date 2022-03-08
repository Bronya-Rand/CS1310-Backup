import java.util.ArrayList;

public class EmployeePolymorphismApp {

    public static void main(String[] args) {
        ArrayList<Employee> hireList = new ArrayList<>();

        // Lets test polymorphism
        // AN object of type employee using constructor of CommissionEmployee
        Employee employee1 = new CommissionEmployee("Ben", "111", .4, 2);
        hireList.add(employee1);

        CommissionEmployee employee2 = new BasePlusCommissionEmployee("Shyann",
                "234", .3, 200, 500);
        hireList.add(employee2);

        // BasePlusCommissionEmployee employee3 = new
        // CommissionEmployee("Dingus", "345", .1, 1);

        for (Employee employee : hireList) {
            System.out.println(employee.toString());
        }
    }
}
