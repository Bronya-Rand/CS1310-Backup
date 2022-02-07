import java.util.Scanner;

/*
Azariel Del Carmen
Java Language
Feb 2, 2022
This class will explore overloading methods
*/

public class SquareValuesApp {
    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);

        System.out.println("Enter an integer value: ");
        int num = input.nextInt();

        System.out.println("Enter a double value: ");
        double dnum = input.nextDouble();

        int iSquare = square(num);
        System.out.println("The square of " + num + " is " + iSquare);
        
        double dSquare = square(dnum);
        System.out.println("The square of " + dnum + " is " + dSquare);
    }

    public static int square(int num) {
        return num * num;
    }

    public static double square(double num) {
        return num * num;
    }
}
