public class Chapter6Question24 {
    
    public static void main(String[] args) {
        for (int i = 1; i <= 1000; i++) {
            isPerfect(i);
        }
    }

    public static void isPerfect(int int1) {
        int sum = 0;

        for (int j = 1; j <= int1/2; j++) {
            if (int1 % j == 0) {
                sum += j;
            }
        }

        if (sum == int1) {
            System.out.printf("%d is a perfect number.%n", int1);
        }
    }
}
