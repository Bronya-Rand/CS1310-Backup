public class StringBuilderTest {
    
    public static void main(String[] args) {
        StringBuilder st = new StringBuilder();
        StringBuilder st1 = new StringBuilder(10);
        StringBuilder st2 = new StringBuilder("Hello");

        //Instance variable length
        //Instance variable capacity
        System.out.println(st.capacity() + ";" + st.length());
        System.out.println(st1.capacity() + ";" + st1.length());
        System.out.println(st2.capacity() + ";" + st2.length());
    }
}
