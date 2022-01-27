import java.util.Scanner;

/*
Azariel Del Carmen
CS2323 
This program determines which integer from a list of 5 integers is the smallest
and largest.
*/

public class Chapter2Question24 {
    
    public static void main(String[] args) {
        Scanner intInput = new Scanner(System.in);
        int smallest;
        int largest;

        System.out.print("Please provide your first integer: ");
        int a = intInput.nextInt();
        smallest = a;

        System.out.print("Please provide your second integer: ");
        int b = intInput.nextInt();

        if (b < a) {
            smallest = b;
            largest = a;
        } else {
            smallest = a;
            largest = b;
        }

        System.out.print("Please provide your third integer: ");
        int c = intInput.nextInt();

        if (c < smallest) {
            smallest = c;
        } else if (c > largest) {
            largest = c;
        }

        System.out.print("Please provide your fourth integer: ");
        int d = intInput.nextInt();

        if (d < smallest) {
            smallest = d;
        } else if (d > largest) {
            largest = d;
        }

        System.out.print("Please provide your fifth integer: ");
        int e = intInput.nextInt();

        if (e < smallest) {
            smallest = e;
        } else if (e > largest) {
            largest = e;
        }

        System.out.printf("From your five given integers [%d, %d, %d, %d, %d]:%n", a, b, c, d, e);
        System.out.printf("The largest number was: %d%n", largest);
        System.out.printf("And the smallest number was: %d%n", smallest);
    }
}
