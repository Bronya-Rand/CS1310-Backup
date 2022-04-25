import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Stack<E> {
    private ArrayList<E> elements;

    public Stack() {
        this(10);
    }

    public Stack(int capacity) {
        elements = new ArrayList<>();
    }

    public void push(E element) {
        elements.add(element);
    }

    public E pull() {
        if (elements.size() == 0) {
            throw new NoSuchElementException("Stack is empty");
        }
        return (elements.remove(elements.size() - 1));
    }

    public E peek() {
        if (elements.isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        return (elements.get(elements.size() - 1));
    }
}
