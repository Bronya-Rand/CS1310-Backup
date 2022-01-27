import java.util.Scanner;

/*
Azariel Del Carmen
CS2323 
This program takes in a integer and determines if the number is even or odd.
*/

public class Chapter2Question25 {

    public static void main(String[] args) {
        Scanner intInput = new Scanner(System.in);

        System.out.print("Please enter a integer to check: ");
        int a = intInput.nextInt();

        if (a % 2 == 0) {
            System.out.printf("%d is a even number.", a);
        } else {
            System.out.printf("%d is a odd number.", a);
        }
    }
}
