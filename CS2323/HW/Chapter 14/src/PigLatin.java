import java.util.Scanner;

public class PigLatin {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a sentence to convert to pig latin: ");
        String sentence = input.nextLine();

        printLatinWord(sentence);
    }

    public static void printLatinWord(String sentence) {
        String temp[] = sentence.split(" ");

        for (int i = 0; i < temp.length; i++) {
            System.out.println(temp[i].substring(1) + temp[i].substring(0, 1) + "ay");
        }
    }
}
