public class Device {

    public enum DeviceType {
        ECHO_DOT, ECHO_SHOW
    };

    private String name;
    private DeviceType type;
    private String wakeWord;
    private int audio;
    private ShoppingCart cart;

    public Device(DeviceType type, String name) {
        this.name = name;
        this.type = type;
        wakeWord = "Alexa";
        audio = 5;
        cart = new ShoppingCart();
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWakeWord(String wakeWord) {
        this.wakeWord = wakeWord;
    }

    public void setAudio(int audio) {
        if (audio < 0 || audio > 10) {
            if (audio < 0) {
                audio = 0;
            } else {
                audio = 10;
            }
        }
        this.audio = audio;
    }

    public void listen(String request) {
        if (request.substring(0, 5).equals(wakeWord)) {
            request = request.replaceAll(wakeWord + " ", "");
            processRequest(request);
        }
    }

    private void processRequest(String request) {
        try {
            if (request.matches("add \\d\\s\\w+(\\s\\w+)\\sto shopping list")) {
                int quantity = Integer.parseInt(request.replaceAll("\\D+", ""));
                String item = request.replaceAll("add \\d\\s", "")
                        .replaceAll("\\sto shopping list", "");

                boolean itemFound = false;
                for (Inventory inventory : AlexaApp.currentInventory) {
                    if (inventory.getName().equals(item)) {
                        itemFound = true;
                        Item temp = new Item(inventory, quantity);
                        cart.addToShoppingCart(temp);
                    }
                }

                if (!itemFound) {
                    System.out.println("Item not available.");
                }
            } else {
                throw new IllegalArgumentException("Invalid Request.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

    public String toString() {
        return String.format("%s", name);
    }
}
