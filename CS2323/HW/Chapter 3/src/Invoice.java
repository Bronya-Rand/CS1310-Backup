public class Invoice {
    
    private String partNumber;
    private String partDescription;
    private int partQuantity;
    private double partPrice;

    Invoice(String partNumber, String partDescription, int partQuantity, double partPrice) {
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        this.partQuantity = partQuantity;
        this.partPrice = partPrice;
    }

    public void setPartNumber(String partNumber) {
        this.partNumber = partNumber;
    }

    public void setPartDescription(String partDescription) {
        this.partDescription = partDescription;
    }
    
    public void setPartQuantity(int partQuantity) {
        this.partQuantity = partQuantity;
    }

    public void setPartPrice(double partPrice) {
        this.partPrice = partPrice;
    }

    public String getPartNumber() {
        return partNumber;
    }

    public String getPartDescription() {
        return partDescription;
    }

    public int getPartQuantity() {
        return partQuantity;
    }

    public double getPartPrice() {
        return partPrice;
    }

    public double getInvoiceAmount() {
        int tempPartQuantity = partQuantity;
        double tempPartPrice = partPrice;

        if (tempPartQuantity < 0) {
            tempPartQuantity = 0;
        } else if (tempPartPrice < 0.0) {
            tempPartPrice = 0.0;
        }

        return tempPartPrice * tempPartQuantity;
    }
}
