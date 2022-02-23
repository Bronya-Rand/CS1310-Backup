public class ReplaceChars {

    public static void main(String[] args) {
        String firstString = "This sentence ends with 5 stars *****";
        String secondString = "digit, digit, digit, 4, 5, 6, 7, 8";

        firstString = firstString.replaceAll("\\*", "^");
        System.out.println(firstString);

        firstString = firstString.replace("stars", "carets");
        System.out.println(firstString);

        for (int i = 1; i < 4; i++) {
            secondString = secondString.replaceFirst("digit", "[i]");
        }
        // i = 1
        // secondString = 1, 1, 1, 4, 5, 6, 7, 8
        // i = 2
        // secondString = 1, 1, 1, 4, 5, 6, 7, 8
        System.out.println(secondString);
    }
}
