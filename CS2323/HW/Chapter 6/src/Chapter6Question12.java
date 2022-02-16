import java.security.SecureRandom;

public class Chapter6Question12 {

    public static void main(String[] args) {
        int n;
        SecureRandom t = new SecureRandom();
        
        //question 1
        n = t.nextInt(2)+ 1;
        System.out.println(n);

        //question 2
        n = t.nextInt(100)+ 1;
        System.out.println(n);

        //question 3
        n = t.nextInt(10);
        System.out.println(n);

        //question 4
        n = t.nextInt(113)+ 1000;
        System.out.println(n);

        //question 5
        n = t.nextInt(3) - 1;
        System.out.println(n);

        //question 6
        n = t.nextInt(15) - 3;
        System.out.println(n);
    }
}
