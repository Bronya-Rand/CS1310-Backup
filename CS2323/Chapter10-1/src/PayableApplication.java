import java.util.ArrayList;

public class PayableApplication {

    public static void main(String[] args) {
        ArrayList<Payable> payableObjects = new ArrayList<>();

        Employee employee1 = new CommissionEmployee("Ian", "111", 1, .2);
        payableObjects.add(employee1);

        try {
            Invoice invoice1 = new Invoice("11", "des", 1, -1);
        } catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }
        try {
            Invoice invoice2 = new Invoice("11", "des", 1, 2);
        } catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }

        for (Payable payable : payableObjects) {
            System.out.println(payableObjects.toString());
        }
    }
}
