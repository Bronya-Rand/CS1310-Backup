import java.util.Scanner;

public class Chapter5Question17 {
    
    public static void main(String[] args) {
        double total = 0.0;
        
        System.out.print("Enter a product number from 1-5 (Ctrl+Z to quit): ");
        Scanner input = new Scanner(System.in);

        while(input.hasNext()) {
            int prodNum = input.nextInt();
            int amount = 0;
            switch (prodNum) {
                case 1:
                    System.out.print("How many items did you purchase?: ");
                    amount = input.nextInt();
                    total = total + (2.98 * amount);
                    break;
                case 2:
                    System.out.print("How many items did you purchase?: ");
                    amount = input.nextInt();
                    total = total + (4.50 * amount);
                    break;
                case 3:
                    System.out.print("How many items did you purchase?: ");
                    amount = input.nextInt();
                    total = total + (9.98 * amount);
                    break;
                case 4:
                    System.out.print("How many items did you purchase?: ");
                    amount = input.nextInt();
                    total = total + (4.49 * amount);
                    break;
                case 5:
                    System.out.print("How many items did you purchase?: ");
                    amount = input.nextInt();
                    total = total + (6.87 * amount);
                    break;
                default:
                    System.out.println("Invalid product number. Please try again.");
                    break;
            }
            System.out.print("Enter a product number from 1-5 (Ctrl+Z to quit): ");
        }
        System.out.printf("Your total for all your purchases is $%.2f", total);
    }
}
