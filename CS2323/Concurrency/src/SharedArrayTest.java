import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SharedArrayTest {

    public static void main(String[] args) {
        // Construct the shared memory
        SimpleArray simpleArray = new SimpleArray(6);

        ArrayWriter writer1 = new ArrayWriter(1, simpleArray);
        ArrayWriter writer2 = new ArrayWriter(11, simpleArray);

        ExecutorService executorService = Executors.newCachedThreadPool();

        executorService.execute(writer1);
        executorService.execute(writer2);

        executorService.shutdown();

        System.out.println(simpleArray.toString());
    }
}
