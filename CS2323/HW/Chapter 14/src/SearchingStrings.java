import java.util.Scanner;

public class SearchingStrings {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int letterArray[] = new int[26];
        char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', 'x', 'y', 'z'};

        System.out.print("Enter a string to count letters: ");
        String sentence = input.nextLine();

        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.toLowerCase().indexOf(letters[i]) != -1) {
                letterArray[i] = letterArray[i] + 1;
            }
        }

        System.out.println("Letter | Occurances");

        for (int i = 0; i < letterArray.length; i++) {
            System.out.printf("   %c        %d%n", letters[i], letterArray[i]);
        }
    }
}
