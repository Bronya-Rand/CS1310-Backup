/**
 * Created by mitrabokaei on 3/4/20.
 */
public enum Inventory {
    KT("kitchen towel"),
    LD("laundry detergent"),
    TP("toilet paper"),
    SP("soap");

    private final String name;

    Inventory(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }
}
