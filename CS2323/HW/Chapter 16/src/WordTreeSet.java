import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;

public class WordTreeSet {

    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a String: ");
        String input = scanner.nextLine();

        String[] tokens = input.trim().split(" ");
        TreeSet<String> sortedTokens = new TreeSet<String>();

        for (String string : tokens) {
            if (!sortedTokens.contains(string)) {
                sortedTokens.add(string);
            }
        }

        System.out.println("Map Contains:");
        for (String string : sortedTokens) {
            System.out.println(string);
        }
    }
}
