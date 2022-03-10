import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.EnumSet;

public class AlexaApp {

    private String id;
    private Device device;
    private SecureRandom random = new SecureRandom();
    public static ArrayList<Inventory> currentInventory = new ArrayList<>();

    public AlexaApp() {
        id = "Alexa_App_" + (1000 + random.nextInt(1001));
        setCurrentInventory();
        System.out.println("Your alexa app is now installed");
        displayCurrentInventory();
    }

    public void setCurrentInventory() {
        for (Inventory inventory : EnumSet.range(Inventory.KT, Inventory.TP)) {
            currentInventory.add(inventory);
        }
    }

    public ArrayList<Inventory> getInventory() {
        return currentInventory;
    }

    public void displayCurrentInventory() {
        for (Inventory inventory : currentInventory) {
            System.out.println(inventory);
        }
    }

    public void addDevice(Device device) {
        this.device = device;
    }
}
