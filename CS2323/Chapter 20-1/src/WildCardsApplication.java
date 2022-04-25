import java.util.ArrayList;
import java.util.List;

public class WildCardsApplication {

    public static void main(String[] args) {
        Number[] arrayNumber = { 1, 3, 2.4, 6.8 };
        List<Number> listNumber = new ArrayList<>();

        for (Number n : arrayNumber) {
            listNumber.add(n);
        }

        sum(listNumber);
    }

    private static <T extends Number> void sum(List<Number> numbers) {
        double sumValue = 0;
        for (Number n : numbers) {
            sumValue += n.doubleValue();
        }
        System.out.println(sumValue);
    }
}
