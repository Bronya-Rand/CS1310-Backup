public class ArrayWriter implements Runnable {

    private final SimpleArray array;
    private final int value;

    public ArrayWriter(int value, SimpleArray array) {
        this.array = array;
        this.value = value;
    }

    @Override
    public void run() {
        for (int i = value; i < value + 3; i++) {
            this.array.add(i);
        }
    }

}
