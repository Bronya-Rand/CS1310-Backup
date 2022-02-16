public class CardGameApp {
    
    public static void main(String[] args) {
        
        DeckOfCards deck1 = new DeckOfCards();

        deck1.shuffle();

        System.out.println(deck1.deal());
    }
}
