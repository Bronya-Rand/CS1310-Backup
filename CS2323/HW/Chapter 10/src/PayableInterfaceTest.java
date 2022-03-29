public class PayableInterfaceTest {

    public static void main(String[] args) {
        Payable[] payableObjects = new Payable[] {
                new Invoice("01234", "seat", 2, 375.00),
                new Invoice("56789", "tire", 4, 79.95),
                new EmployeePayable("Eula", "Lawrance", "111", new SalariedCompensationModel(800)),
                new EmployeePayable("Yun", "Jin", "222", new SalariedCompensationModel(1200))
        };

        System.out.println("Invoices and Employees processed polymorphically:");

        for (Payable currentPayable : payableObjects) {
            System.out.printf("%n%s %npayment due: $%,.2f%n", currentPayable.toString(),
                    currentPayable.getPaymentAmount());
        }
    }
}
