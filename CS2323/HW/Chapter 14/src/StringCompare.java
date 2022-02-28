public class StringCompare {
    
    public static void main(String[] args) {
        String first = "First";
        String second = "Second";

        check(first, second);

        first = "Second";
        check(first, second);

        first = "Seventh";
        check(first, second);
    }

    public static void check(String first, String second) {
        if (first.compareTo(second) == 0) {
            System.out.println("Both strings are equal.");
        }
        else if (first.compareTo(second) > 0) {
            System.out.println("First string is greater than second.");
        }
        else {
            System.out.println("Second string is greater than first.");
        }
    }
}
