import java.util.Scanner;

public class MorseToEnglish {
    
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
        System.out.print("Enter a morse string to convert to english: ");
        String sentence = input.nextLine();
        String temp[] = sentence.split("   ");
        
        System.out.print("Your string in morse code is: ");
        for (int i = 0; i < temp.length; i++) {
            if (i != 0 || i == temp.length-1) {
                System.out.print(" ");
            }
            String tempTwo[] = temp[i].split(" ");
            for (int j = 0; j < tempTwo.length; j++) {
                for (int j2 = 0; j2 < code.length; j2++) {
                    if (tempTwo[j].compareTo(code[j2]) == 0) {
                        System.out.print(letter[j2]);
                        break;
                    }
                }
            }
        }
    }
}
