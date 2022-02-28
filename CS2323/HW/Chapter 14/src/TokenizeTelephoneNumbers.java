import java.util.Scanner;

public class TokenizeTelephoneNumbers {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a phone number with () and -'s: ");
        String number = input.nextLine();

        String areaCode = number.split(" ")[0].replace("(", "").replace(")", "");
        String firstThree = number.split(" ")[1].split("-")[0];
        String lastFour = number.split(" ")[1].split("-")[1];

        System.out.printf("Area Code: %s%n", areaCode);
        System.out.printf("7 Numbers: %s - %s%n", firstThree, lastFour);
    }
}
