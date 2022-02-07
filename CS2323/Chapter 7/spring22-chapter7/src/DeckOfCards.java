public class DeckOfCards {
    
    private final int noCards = 52;
    private Card[] deck = new Card[noCards];

    public DeckOfCards() {
        String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

        for (int i = 0; i < noCards; i++) {
            deck[i] = new Card(faces[i%13], suits[i/13]);
        }

        
    }
}
