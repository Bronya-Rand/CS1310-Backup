import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class WordTypeCount {

    public static void main(String[] args) {
        Map<String, Integer> myMap = new HashMap<>();

        createMap(myMap);
        displayMap(myMap);
    }

    public static void createMap(Map<String, Integer> myMap) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a sentence:\n");

        String sentence = input.nextLine();

        String[] tokens = sentence.trim().split(" ");

        for (String string : tokens) {
            if (myMap.containsKey(string)) {
                int count = myMap.get(string) + 1;
                myMap.put(string, count);
            } else {
                myMap.put(string, 1);
            }
        }
    }

    private static void displayMap(Map<String, Integer> myMap) {
        for (String key : myMap.keySet()) {
            System.out.println(key + " : " + myMap.get(key));
        }
    }
}
