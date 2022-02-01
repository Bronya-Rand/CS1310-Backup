import java.util.Scanner;

/*
Azariel Del Carmen
CS2323 
This program takes in two integers and returns to the screen the sum, difference,
product and quotient results of them.
*/

public class Chapter2Question15 {
    
    public static void main(String[] args) {
        Scanner intInput = new Scanner(System.in);
        
        //prompt user for 1st integer
        System.out.print("Please enter your first integer: ");
        int a = intInput.nextInt();
        
        //prompt user for 2nd integer
        System.out.print("\nPlease enter your second integer: ");
        int b = intInput.nextInt();
        
        //display results
        System.out.printf("Here are the results for numbers %d and %d:%n", a, b);
        System.out.printf("%d%s%d%s%d%n", a, " + ", b, " = ", a+b);
        System.out.printf("%d%s%d%s%d%n", a, " - ", b, " = ", a-b);
        System.out.printf("%d%s%d%s%d%n", a, " * ", b, " = ", a*b);
        if(b == 0) {
            System.out.printf("%d%s%d%s%s%n", a, " / ", b, " = ", "undefined");
        }
        else {
            System.out.printf("%d%s%d%s%d%n", a, " / ", b, " = ", a/b);
        }
    }
}
