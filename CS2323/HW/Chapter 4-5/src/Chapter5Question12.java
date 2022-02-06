public class Chapter5Question12 {
    
    public static void main(String[] args) {
        int total = 1;

        for (int x = 1; x <= 15; x++) {
            if (x % 2 != 0) {
                total *= x;
            }
        }
        System.out.printf("The product of odd integers from 1-15 is %d", total);
    }
}
