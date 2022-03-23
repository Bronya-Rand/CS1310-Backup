import java.util.ArrayList;
import java.util.Scanner;

public class FactoryTestApp {

    public static void main(String[] args) {
        System.out.println(
                "Enter your numbers for different compensation models and employee name/ssn (seperated with comma)");
        System.out.println("1 - Commission Employee");
        System.out.println("2 - Base Plus Commission Employee");
        System.out.println("To terminate press Ctrl+Z");

        ArrayList<Employee> employees = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        EmployeeFactoryClass factoryClass = new EmployeeFactoryClass();

        while (input.hasNext()) {
            String[] info = input.next().trim().split(",");
            if (info.length == 3) {
                employees.add(factoryClass.EmployeeFactory(info[0], info[1],
                        info[2]));
            } else {
                System.out.println("Invalid input. Please try again.");
            }
            // ask the factory class to return us an Employee object of specific
            // compensation type

        }

        for (Employee emp : employees) {
            System.out.println(emp.toString());
        }
    }
}
