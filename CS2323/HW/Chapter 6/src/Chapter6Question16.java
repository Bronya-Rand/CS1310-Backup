import java.util.Scanner;

public class Chapter6Question16 {
    
    public static void main(String[] args) {
        int int1, int2;
        Scanner input = new Scanner(System.in);

        System.out.print("Please type your first integer: ");
        int1 = input.nextInt();

        System.out.print("Please type your 2nd integer: ");
        int2 = input.nextInt();

        if (isMultiple(int1, int2)) {
            System.out.printf("%n%d is a multiple of %d%n", int2, int1);
        } else {
            System.out.printf("%n%d is not a multiple of %d%n", int2, int1);
        }
    }

    public static boolean isMultiple(int int1, int int2) {
        if (int2 % int1 == 0) {
            return true;
        }
        return false;
    }
}
