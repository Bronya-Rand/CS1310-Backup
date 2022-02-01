public class InvoiceTest {
    
    public static void main(String[] args) {
        Invoice part1 = new Invoice("5", "Dell Laptop Camera", 15, 35.49);
        Invoice part2 = new Invoice("99", "MX100 Clones", -156, 4.99);
        Invoice part3 = new Invoice("51", "iPhone X", 43, -499.99);

        //display current invoices ATM
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part1.getPartNumber(), part1.getPartDescription(), part1.getPartQuantity(),
            part1.getPartPrice());
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part2.getPartNumber(), part2.getPartDescription(), part2.getPartQuantity(),
            part2.getPartPrice());
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part3.getPartNumber(), part3.getPartDescription(), part3.getPartQuantity(),
            part3.getPartPrice());

        //calculate invoice prices
        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n", part1.getPartNumber(), 
            part1.getInvoiceAmount());
        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n", part2.getPartNumber(), 
            part2.getInvoiceAmount());
        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n%n", part3.getPartNumber(), 
            part3.getInvoiceAmount());

        System.out.println("Fixing invoices\n");
        part2.setPartQuantity(9);
        part3.setPartDescription("iPhone X (Original)");
        part3.setPartPrice(349.99);
        part1.setPartNumber("21");

        //display current invoices now
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part1.getPartNumber(), part1.getPartDescription(), part1.getPartQuantity(),
            part1.getPartPrice());
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part2.getPartNumber(), part2.getPartDescription(), part2.getPartQuantity(),
            part2.getPartPrice());
        System.out.printf("Part #: %s%nPart Description: %s%nPart Quantity: %d%nPart Price: $%.2f%n%n", 
            part3.getPartNumber(), part3.getPartDescription(), part3.getPartQuantity(),
            part3.getPartPrice());

        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n", part1.getPartNumber(), 
            part1.getInvoiceAmount());
        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n", part2.getPartNumber(), 
            part2.getInvoiceAmount());
        System.out.printf("Invoice for Part #%s%nTotal: %.2f%n%n", part3.getPartNumber(), 
            part3.getInvoiceAmount());
    }
}
