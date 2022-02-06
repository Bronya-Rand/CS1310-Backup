// Fig. 5.13: BreakTest.java
// break statement exiting a for statement.
public class BreakTest {
    public static void main(String[] args) {
        int count; // control variable also used after loop terminates

        for (count = 1; count < 5; count++) { 
            System.out.printf("%d ", count);
        }
        System.out.printf("%nBroke out of loop at count = %d%n", count);
    }
}
