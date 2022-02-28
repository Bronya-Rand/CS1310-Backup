public class TimeApp {

    public static void main(String[] args) {
        try {
            Time t1 = new Time(25, 1, 4);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.println("Hey my program did not terminate!!");
        // System.out.println(t1.toString());
    }
}
