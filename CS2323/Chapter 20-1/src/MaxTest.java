public class MaxTest {

    public static void main(String[] args) {
        System.out.println(maximum(3, 8, 1));

        System.out.println(maximum(2.4, 5.7, 1.1));

        System.out.println(maximum('c', 'H', 'p'));

        System.out.println(maximum(new Employee("Ian", "123", 14),
                new Employee("Savannah", "234", 1000),
                new Employee("Jacques", "345", 900)));
    }

    private static <T extends Comparable<T>> T maximum(T a, T b, T c) {
        T max = a;
        if (b.compareTo(max) > 0) {
            max = b;
        }
        if (c.compareTo(max) > 0) {
            max = c;
        }
        return max;
    }
}
