import java.util.ArrayList;

public class ShoppingCart {

    private ArrayList<Item> items = new ArrayList<>();

    public void addToShoppingCart(Item item){
        if(items.contains(item)){
            throw new IllegalArgumentException("Item already exists in your shopping cart");
        }
        items.add(item);
        displayShoppingCart();
    }

    public void displayShoppingCart(){
        for(Item item: items){
            System.out.println(item.toString());
        }
    }
}
