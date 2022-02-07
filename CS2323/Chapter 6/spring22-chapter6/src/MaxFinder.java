import java.util.Scanner;

public class MaxFinder {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter your first value:");
        double num1 = input.nextDouble();

        System.out.println("Enter your second value:");
        double num2 = input.nextDouble();

        System.out.println("Enter your third value:");
        double num3 = input.nextDouble();

        double max = maximumFinder(num1, num2, num3);
        System.out.println("The maximum of " + num1 + " " + num2 + " " + num3 + " is " +
            max);
    }

    public static double maximumFinder(double num1, double num2, double num3) {
        double max = num1;

        if (num2 > max) {
            max = num2;
        }
        if (num3 > max) {
            max = num3;
        }

        return max;
    }
}
