import java.util.Scanner;

public class ReversedSentence {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a sentence: ");
        String sentence = input.nextLine();

        String temp[] = sentence.split(" ");

        for (int i = temp.length-1; i >= 0; i--) {
            System.out.print(temp[i]);
            if (i > 0) {
                System.out.print(" ");
            } else {
                System.out.print(".");
            }
        }
    }
}
