import java.util.Scanner;

/*
Azariel Del Carmen
CS2323 
This program takes in a integer as a radius and calculates the circumference,
diameter, and area of a circle.
*/

public class Chapter2Question28 {
    
    public static void main(String[] args) {
        Scanner radiusInput = new Scanner(System.in);
        
        System.out.print("Please enter a whole number for your radius: ");
        int radius = radiusInput.nextInt();

        System.out.printf("The results of a circle with a radius of %d is:%n", radius);
        System.out.printf("Diameter: %d%n", 2*radius);
        System.out.printf("Circumference: %.2f%n", 2*Math.PI*radius);
        System.out.printf("Area: %.2f%n", Math.PI*(radius*radius));
    }
}
