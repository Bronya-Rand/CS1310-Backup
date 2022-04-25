public class DummyMainClass {

    public static void main(String[] args) {
        Integer[] iArray = { 1, 2, 3, 4, 5 };
        Double[] dArray = { 1.4, 2.6, 3.0, 4.2, 5.9 };
        Character[] cArray = { 'h', 'A', 'B', 'p' };

        printValues(iArray);
        printValues(dArray);
        printValues(cArray);
    }

    private static <T> void printValues(T[] iArray) {
        for (T t : iArray) {
            System.out.printf("%s ", t);
        }
    }
}
