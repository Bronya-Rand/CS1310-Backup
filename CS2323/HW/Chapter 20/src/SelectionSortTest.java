import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SelectionSortTest {
    public static <T extends Comparable<T>> void selectionSort(
            ArrayList<T> data) {
        for (int i = 0; i < data.size() - 1; i++) {
            int smallest = i;

            for (int index = i + 1; index < data.size(); index++) {
                if (data.get(index).compareTo(data.get(smallest)) < 0) {
                    smallest = index;
                }
            }
            swap(data, i, smallest);
            printPass(data, i + 1, smallest);
        }
    }

    private static <T> void swap(ArrayList<T> data, int first, int second) {
        T temporary = data.get(first);
        data.set(first, data.get(second));
        data.set(second, temporary);
    }

    private static <T> void printPass(ArrayList<T> data, int pass, int index) {
        System.out.printf("after pass %2d: ", pass);

        for (int i = 0; i < index; i++) {
            System.out.printf("%s  ", data.get(i));
        }
        System.out.printf("%s* ", data.get(index));

        for (int i = index + 1; i < data.size(); i++) {
            System.out.printf("%s  ", data.get(i));
        }
        System.out.printf("%n   ");

        for (int j = 0; j < pass; j++) {
            System.out.print("--  ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        SecureRandom generator = new SecureRandom();

        int[] data = generator.ints(10, 10, 91).toArray();
        // problem said float but there was no float so double instead
        double[] data_two = generator.doubles(10, 10.0, 91.0).toArray();

        ArrayList<Integer> int_data = new ArrayList<>();
        ArrayList<Double> double_data = new ArrayList<>();

        for (int d : data) {
            int_data.add(d);
        }

        for (double d : data_two) {
            double_data.add(d);
        }

        System.out.printf("Integer Unsorted array: %s%n%n",
                int_data.toString());
        selectionSort(int_data);
        System.out.printf("Integer Sorted array: %s%n%n", int_data.toString());

        System.out.printf("Double Unsorted array: %s%n%n",
                double_data.toString());
        selectionSort(double_data);
        System.out.printf("Double Sorted array: %s%n%n",
                double_data.toString());
    }
}
