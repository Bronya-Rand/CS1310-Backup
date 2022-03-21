public class CompensationModelApp {

    public static void main(String[] args) {

        CommissionCompensationModel emp1 = new CommissionCompensationModel(1500, .25);
        BasePlusCommissionCompensationModel emp2 = new BasePlusCommissionCompensationModel(100, .15, 6000);

        EmployeeComposition employee1 = new EmployeeComposition("Tom", "Jones", "111", emp1);
        EmployeeComposition employee2 = new EmployeeComposition("Sara", "Lee", "222", emp2);

        System.out.printf("%s %s%n", "Employee 1's Earnings:", employee1.earnings());
        System.out.printf("%s %s%n", "Employee 2's Earnings:", employee2.earnings());
    }
}
