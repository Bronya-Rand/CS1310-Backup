public class Factorials {
    
    public static void main(String[] args) {
        long total = 1;
        
        System.out.println("Num\tTotal");
        System.out.println("-------------");

        for (int x = 1; x <= 20; x++) {
            if (x % 2 == 0) {
                total *= x;
                System.out.printf("%d\t%d%n", x, total);
            }
        }
    }
}
