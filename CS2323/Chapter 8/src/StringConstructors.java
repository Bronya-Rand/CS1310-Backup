public class StringConstructors {
    
    public static void main(String[] args) {
        String s1 = new String("CS2323");

        String s2 = new String();

        char[] charArray = {'o', 'o', 'p', 'I', 'I'};
        String s3 = new String(charArray);

        String s4 = new String(charArray, 0, 3);

        System.out.printf("s1 = %s, s2 = %s, s3 = %s, s4 = %s%n", s1, s2.toString(), s3, s4);  

        char[] charArray2 = new char[5];
        System.out.printf("s1 length is: %d", s1.length());

        s1.getChars(0, 5, charArray2, 0);

        for (char c : charArray2) {
            System.out.println(c);
        }

        String s5 = "CS2323";

        if (s1.equals(s5)) {
            System.out.println("S1 is equal to S5");
        }

        if (s1 == s5) {
            System.out.println("S1 is equal to S5");
        }

        String s6 = "cs2323";
        if (s5.equalsIgnoreCase(s6)) {
            System.out.println("S5 is equal to S6");
        }

        String s7 = "I am teaching CS2323 in spring semester";
        if (s7.regionMatches(0, s1, 0, 6)) {
            System.out.println("Found the string");
        }
    }
}
