import java.security.SecureRandom;
import java.util.Arrays;

public class SimpleArray {

    private final int[] array;
    private int arraySize;
    private int writeIndex = 0;

    private final SecureRandom secureRandom = new SecureRandom();

    public SimpleArray(int arraySize) {
        this.arraySize = arraySize;
        array = new int[arraySize];
    }

    // Define a functionality for this array
    public void add(int value) {
        int position = writeIndex;
        try {
            Thread.sleep(secureRandom.nextInt(5000));
        } catch (InterruptedException e) {
            e.printStackTrace();
            Thread.currentThread().interrupt();
        }
        System.out.printf("%s wrote %d to element %d%n",
                Thread.currentThread().getName(), value, position);
        ++writeIndex;
        System.out.println("The next write index is: " + writeIndex);
    }

    public String toString() {
        return Arrays.toString(array);
    }
}
