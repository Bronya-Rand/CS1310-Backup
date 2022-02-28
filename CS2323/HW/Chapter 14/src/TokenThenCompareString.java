import java.util.Scanner;

public class TokenThenCompareString {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int occurances = 0;

        System.out.print("Enter a string to count the letter 'b': ");
        String sentence = input.nextLine();

        String temp[] = sentence.toLowerCase().split(" ");

        for (int i = 0; i < temp.length; i++) {
            for (int j = 0; j < temp[i].length(); j++) {
                if (temp[i].indexOf("b", j) != -1) {
                    occurances++;
                }
            }
        }

        System.out.printf("Occurances of 'b': %d", occurances);
    }
}
