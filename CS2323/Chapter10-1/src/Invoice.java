public class Invoice implements Payable {

    private String partNumber;
    private String partDescription;
    private int quantity;
    private double pricePerItem;

    public Invoice(String partNumber, String partDescription, int quantity, double pricePerItem) {
        if (pricePerItem < 0.0) {
            throw new IllegalArgumentException("Price per item is invalid.");
        }
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        this.quantity = quantity;
        this.pricePerItem = pricePerItem;
    }

    @Override
    public double getPayableAmount() {
        // TODO Auto-generated method stub
        return pricePerItem * quantity;
    }

}
