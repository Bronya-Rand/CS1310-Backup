import java.security.SecureRandom;

public class RandomSentences {
    
    public static void main(String[] args) {
        String article[] = {"the", "a", "one", "some"};
        String noun[] = {"boy", "girl", "dog", "town", "car"};
        String verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
        String preposition[] = {"to", "from", "over", "under", "on"};
        SecureRandom random = new SecureRandom();
        int capitalInt;
        
        for (int i = 0; i <= 20; i++) {
            capitalInt = random.nextInt(4);
            System.out.print(article[capitalInt].substring(0, 1).toUpperCase() + article[capitalInt].substring(1));
            System.out.print(" ");
            System.out.print(noun[random.nextInt(5)]);
            System.out.print(" ");
            System.out.print(verb[random.nextInt(5)]);
            System.out.print(" ");
            System.out.print(preposition[random.nextInt(5)]);
            System.out.print(".\n");
        }
    }
}
