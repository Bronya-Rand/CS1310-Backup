import java.security.SecureRandom;

public class DeckOfCards {
    
    private final int noCards = 52;
    private Card[] deck = new Card[noCards];
    private int topCard = 0;

    public DeckOfCards() {
        String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

        for (int i = 0; i < noCards; i++) {
            deck[i] = new Card(faces[i%13], suits[i/13]);
        }
    }

    public void shuffle() {
        SecureRandom random = new SecureRandom();
        int randomIndex;
        for (int i = 0; i < deck.length; i++) {
            randomIndex = random.nextInt();
            Card temp = deck[i];
            deck[i] = deck[randomIndex];
            deck[randomIndex] = temp;
        }
    }

    public Card deal() {
        if (topCard < deck.length) {
            return (deck[topCard++]);
        }
        return null;
    }
}
