public class CompensationModelApp {

    public static void main(String[] args) {

        EmployeeComposition employee1 = new EmployeeComposition("Tom", "Jones", "111",
                new CommissionCompensationModel(1500, .25));
        EmployeeComposition employee2 = new EmployeeComposition("Sara", "Lee", "222",
                new BasePlusCommissionCompensationModel(100, .15, 6000));
        EmployeeComposition employee3 = new EmployeeComposition("Kamisato", "Ayaka", "333",
                new SalariedCompensationModel(350));
        EmployeeComposition employee4 = new EmployeeComposition("Eula", "Lawrence", "444",
                new HourlyCompensationModel(465, 7.5));

        System.out.printf("%s %s%n", "Employee 1's Earnings:", employee1.earnings());
        System.out.printf("%s %s%n", "Employee 2's Earnings:", employee2.earnings());
        System.out.printf("%s %s%n", "Employee 3's Earnings:", employee3.earnings());
        System.out.printf("%s %s%n", "Employee 4's Earnings:", employee4.earnings());
    }
}
