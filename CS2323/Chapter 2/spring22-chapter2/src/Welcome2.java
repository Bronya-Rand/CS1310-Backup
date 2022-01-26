package src;

import java.util.Scanner;

/*
Azariel Del Carmen
Java Programming Language
Date: Jan 24, 2022
This program demostrates how to use scanner to read from standard input
*/

public class Welcome2 {
    
    public static void main(String[] args) {
        
        //instantiate an object from Scanner
        Scanner pizza = new Scanner(System.in);

        System.out.println("Enter a number:");
        int a;

        a = pizza.nextInt();
        System.out.printf("%s%d%n", "You entered ", a);

        int b;
        System.out.print("Enter your second number");
        b = pizza.nextInt();

        int c = a+b;
        
        //a + b = c
        System.out.printf("%d%s%d%s%d%n", a, " + ", b, " = ", c);

    }
}
