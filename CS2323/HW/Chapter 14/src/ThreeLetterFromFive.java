import java.util.Scanner;

public class ThreeLetterFromFive {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a 5 letter string: ");
        String word = input.nextLine();

        if (word.length() < 0 || word.length() > 6) {
            System.out.printf("%s has a insufficient word length (%d). Try again.", word, word.length());
        } else {
            for (int i = 0; i < word.length(); i++) {
                for (int j = i + 1; j < word.length(); j++) {
                    for (int j2 = j + 1; j2 < word.length(); j2++) {
                        System.out.println(word.charAt(i) + "" + word.charAt(j)+ "" + word.charAt(j2));
                    }
                }
            }
        }
    }
}
