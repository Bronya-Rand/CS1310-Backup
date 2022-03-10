/**
 * Created by mitrabokaei on 3/4/20.
 */
public class Item {

    private Inventory item;
    private int quantity;

    public Item(Inventory item, int quantity){
        this.item = item;
        this.quantity = quantity;
    }

    public void setItem(Inventory item){
        this.item = item;
    }

    public Inventory getItem(){
        return item;
    }

    public void setQuantity(int quantity){
        this.quantity = quantity;
    }

    public int getQuantity(){
        return quantity;
    }

    public String toString(){
        return String.format("%s %d", item.toString(), quantity);
    }
}
