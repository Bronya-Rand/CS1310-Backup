import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class PrintTest {

    public static void main(String[] args) {
        PrintTask task1 = new PrintTask("task1");
        task1.getVar();

        PrintTask task2 = new PrintTask("Dr. Hanna's printing");
        PrintTask task3 = new PrintTask("Dr. Barsoum's printing");
        PrintTask task4 = new PrintTask("Dr. B's printing");

        // Use ExecutorService to create threads
        ExecutorService executorService = Executors.newCachedThreadPool();

        executorService.execute(task1);
        executorService.execute(task2);
        executorService.execute(task3);
        executorService.execute(task4);

        executorService.shutdown();
    }
}
