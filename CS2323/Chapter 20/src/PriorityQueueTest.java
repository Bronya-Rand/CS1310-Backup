import java.util.PriorityQueue;

public class PriorityQueueTest {

    public static void main(String[] args) {
        PriorityQueue<Double> queue = new PriorityQueue<>();
        // double -> primative type; just like int
        // Double -> reference type
        // insert elements
        queue.offer(9.7);
        queue.offer(3.2);
        queue.offer(5.4);

        System.out.print("Polling from queue: ");

        // display elements in queue
        while (queue.size() > 0) {
            System.out.printf("%.1f ", queue.peek());
            queue.poll(); // remove top element
        }
    }
}
