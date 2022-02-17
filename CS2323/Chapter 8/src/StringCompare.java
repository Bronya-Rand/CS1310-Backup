public class StringCompare {
    
    public static void main(String[] args) {
        String s1 = "Happy Birthday";
        String s2 = "happy birthday";

        if(s1.regionMatches(false, 0, s2, 0, 5)) {
            System.out.println("First 5 characters of s1 matches s2");
        }

        if(s1.regionMatches(true, 0, s2, 0, 5)) {
            System.out.println("First 5 characters of s1 matches s2 with case ignored");
        }
    }
}
