public class EmployeeTest {

    public static void main(String[] args) {
        // creating a object from BasePlusCommission

        BasePlusCommissionEmployee employee1 = new BasePlusCommissionEmployee(
                "Ian", "111", 2, 0.1, 100);

        CommissionEmployee employee2 = new BasePlusCommissionEmployee("Dingus",
                "123", 0, 0.1, 100);

        System.out.println(employee1.toString());
        System.out.println(employee2.toString());
    }
}
