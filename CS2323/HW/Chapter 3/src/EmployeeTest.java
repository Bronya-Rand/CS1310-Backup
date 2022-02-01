public class EmployeeTest {
    
    public static void main(String[] args) {
        Employee emp1 = new Employee("James", "Greyton", 547.49);
        Employee emp2 = new Employee("Rebecca", "Leon", 486.43);

        //display current info
        System.out.printf("Employee 1%nName: %s %s%nSalary: %.2f%n%n", emp1.getFirstName(),
            emp1.getLastName(), emp1.getSalary());
        System.out.printf("Employee 2%nName: %s %s%nSalary: %.2f%n%n", emp2.getFirstName(),
            emp2.getLastName(), emp2.getSalary());
        
        System.out.println("Giving employees a 10% raise");
        emp1.setSalary(emp1.getSalary() * 1.10);
        emp2.setSalary(emp2.getSalary() * 1.10);

        System.out.println("Updating employee info\n");
        emp1.setFirstName("Jordan");
        emp2.setLastName("De La Garza");

        //display update results
        System.out.printf("Employee 1%nName: %s %s%nSalary: %.2f%n%n", emp1.getFirstName(),
            emp1.getLastName(), emp1.getSalary());
        System.out.printf("Employee 2%nName: %s %s%nSalary: %.2f%n%n", emp2.getFirstName(),
            emp2.getLastName(), emp2.getSalary());
    }
}
