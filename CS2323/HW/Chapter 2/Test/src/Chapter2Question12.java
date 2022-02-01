/*
Azariel Del Carmen
CS2323 
This program tests different math statements in order to get a valid math answer
*/

public class Chapter2Question12 {
    
    public static void main(String[] args) {
        int a = 2;
        int x = 5;
        
        //display results of 2 and 5. result should be 257
        System.out.printf("a * x * x * x + 7 = %d%n", a*x*x*x+7);
        System.out.printf("a * x * x * (x + 7) = %d%n", a*x*x*(x+7));
        System.out.printf("(a * x) * x * (x + 7) = %d%n", (a*x)*x*(x+7));
        System.out.printf("(a * x) * x * x + 7 = %d%n", (a*x)*x*x+7);
        System.out.printf("a * (x * x * x) + 7 = %d%n", a*(x*x*x)+7);
        System.out.printf("a * x * (x * x + 7) = %d%n", a*x*(x*x+7));
    }
}
