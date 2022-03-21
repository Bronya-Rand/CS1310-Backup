import java.util.Scanner;

public class FactoryTestApp {

    public static void main(String[] args) {
        System.out.println("Enter your numbers for different compensation models");
        System.out.println("1 - Commission Employee");
        System.out.println("2 - Base Plus Commission Employee");
        System.out.println("To terminate press Ctrl+Z");

        Scanner input = new Scanner(System.in);
        String option = "";
        while (input.hasNext()) {
            option = input.next();
            // ask the factory class to return us an Employee object of specific
            // compensation type

        }
    }
}
