import java.util.Scanner;

public class SearchingStrings {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int letterArray[] = new int[25];
        char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'w', 'x', 'y', 'z' };

        System.out.print("Enter a string to count letters: ");
        String sentence = input.nextLine();

        for (int i = 0; i < sentence.length(); i++) {
            for (int j = 0; j < letters.length; j++) {
                if (sentence.charAt(i) == letters[j]) {
                    letterArray[j] = letterArray[j] + 1;
                }
            }
        }

        System.out.println("Letter | Occurances");

        for (int i = 0; i < letterArray.length; i++) {
            System.out.printf("   %c        %d%n", letters[i], letterArray[i]);
        }
    }
}
