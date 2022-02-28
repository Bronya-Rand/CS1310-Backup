import java.util.Scanner;

public class MorseCode {
    
    public static void main(String[] args) {
        char[] letter = { 'a', 'b', 'c', 'd', 'e', 'f',
                          'g', 'h', 'i', 'j', 'k', 'l',
                          'm', 'n', 'o', 'p', 'q', 'r',
                          's', 't', 'u', 'v', 'w', 'x',
                          'y', 'z', '1', '2', '3', '4',
                          '5', '6', '7', '8', '9', '0', ' '};
        
        String[] code
            = { ".-",   "-...", "-.-.", "-..",  ".",
                "..-.", "--.",  "....", "..",   ".---",
                "-.-",  ".-..", "--",   "-.",   "---",
                ".--.", "--.-", ".-.",  "...",  "-",
                "..-",  "...-", ".--",  "-..-", "-.--",
                "--..", ".----", "..---", "…--", "….-",
                "…..", "-….", "--…", "---..", "----.", "-----",
                "   "};

        Scanner input = new Scanner(System.in);
        System.out.print("Enter a string to convert to morse: ");
        String sentence = input.nextLine().toLowerCase();
        
        System.out.print("Your string in morse code is: ");
        for (int i = 0; i < sentence.length(); i++) {
            int j = 0;
            while (sentence.charAt(i) != letter[j]) {
                j++;
            }
            System.out.print(code[j] + " ");
        }
    }
}
