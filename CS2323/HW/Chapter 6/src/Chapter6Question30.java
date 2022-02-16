import java.security.SecureRandom;
import java.util.Scanner;

public class Chapter6Question30 {
    
    public static void main(String[] args) {
        SecureRandom random = new SecureRandom();
        Scanner input = new Scanner(System.in);

        int digitToGuess = random.nextInt(1000) + 1;
        int guessNumber = 0;

        System.out.println("A random number between 1-1000 has been generated.");
        while (guessNumber != digitToGuess) {
            System.out.print("What is this number?: ");
            guessNumber = input.nextInt();
            
            if (digitToGuess < guessNumber) {
                System.out.println("Your guess was too high.\n");
            } else if (digitToGuess > guessNumber) {
                System.out.println("Your guess was too low.\n");
            }
        }
        System.out.println("You guessed the number correctly!");
    }
}
