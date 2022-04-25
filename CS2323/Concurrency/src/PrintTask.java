import java.security.SecureRandom;

public class PrintTask implements Runnable {

    private final String taskName;
    // declared but not initialized
    private String var;

    private final SecureRandom random = new SecureRandom();
    private final int sleepTime;

    public PrintTask(String name) {
        this.taskName = name;
        sleepTime = random.nextInt(5000);
    }

    @Override
    public void run() {
        System.out.println("Start printing " + taskName);
        try {
            Thread.sleep(sleepTime);
        } catch (InterruptedException e) {
            e.printStackTrace();
            Thread.currentThread().interrupt();
        }
        System.out.println(taskName + " Done Sleeping for " + sleepTime);
    }

    public String getTaskName() {
        return taskName;
    }

    public String getVar() {
        return var;
    }
}
