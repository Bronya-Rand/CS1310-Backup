import java.security.SecureRandom;

public class RollDie {
    
    public static void main(String[] args) {
        //Creating a instance from SecureRandom
        SecureRandom random = new SecureRandom();

        int[] frequency = new int[7];

        for (int i = 1; i <= 60_000_000; i++) {
            int rand = 1 + random.nextInt(6);
            ++frequency[rand];
        }

        for (int j = 1; j < frequency.length; j++) {
            System.out.println(frequency[j]);
        }
    }
}
