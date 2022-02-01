import java.util.Scanner;

/*
Azariel Del Carmen
CS2323 
This program takes in a 5 length integer and splits them into 5 numbers with spaces
e.g "1 2 3 4 5"
*/

public class Chapter2Question30 {
    
    public static void main(String[] args) {
        Scanner intInput = new Scanner(System.in);

        //prompt the user for a 5 digit integer
        System.out.print("Please enter a 5 digit integer: ");
        int a = intInput.nextInt();

        //checks whether the number is 5 digits long to continue program, else error
        if (a > 99999) {
            System.out.println("Error: Your number is more than 5 digits long.");
        } else if (a < 10000) {
            System.out.println("Error: Your number is less than 5 digits long.");
        }
        else {
            System.out.printf("%d split is:%n", a);
            System.out.printf("%d %d %d %d %d", (a/10000)%10, (a/1000)%10, (a/100)%10, (a/10)%10, a%10);
        }
    }
}
