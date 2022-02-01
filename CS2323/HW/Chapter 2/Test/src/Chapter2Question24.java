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

        //prompt user for 1st integer
        System.out.print("Please provide your first integer: ");
        int a = intInput.nextInt();
        smallest = a;

        //prompt user for 2nd integer
        System.out.print("Please provide your second integer: ");
        int b = intInput.nextInt();

        //compare if 2nd int is less than 1st int, else its largest
        if (b < a) {
            smallest = b;
            largest = a;
        } else {
            smallest = a;
            largest = b;
        }
        
        //prompt user for 3rd integer
        System.out.print("Please provide your third integer: ");
        int c = intInput.nextInt();

        //compare if 3rd int is less than the smallest number then largest
        if (c < smallest) {
            smallest = c;
        } else if (c > largest) {
            largest = c;
        }
        
        //prompt user for 4th integer
        System.out.print("Please provide your fourth integer: ");
        int d = intInput.nextInt();

        //compare if 4th int is less than the smallest number then largest
        if (d < smallest) {
            smallest = d;
        } else if (d > largest) {
            largest = d;
        }

        //prompt user for 5th integer
        System.out.print("Please provide your fifth integer: ");
        int e = intInput.nextInt();

        //compare if 5th int is less than the smallest number then largest
        if (e < smallest) {
            smallest = e;
        } else if (e > largest) {
            largest = e;
        }

        //display results
        System.out.printf("From your five given integers [%d, %d, %d, %d, %d]:%n", a, b, c, d, e);
        System.out.printf("The largest number was: %d%n", largest);
        System.out.printf("And the smallest number was: %d%n", smallest);
    }
}
