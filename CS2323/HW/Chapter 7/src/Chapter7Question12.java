import java.util.Scanner;

public class Chapter7Question12 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] array = new int[5];
        int count = 0;
        int temp = 0;

        System.out.print("Please type in a unique integer: ");
        while(count <= 4) {
            boolean unique = true;
            temp = input.nextInt();

            for (int i : array) {
                if (temp == i) {
                    unique = false;
                }
            }

            if (unique) {
                System.out.printf("You entered unique number %d%n", temp);
                array[count] = temp;
                count++;
            }
            if (count <= 4) {
                System.out.print("Please type in a unique integer: ");
            }
        }
        System.out.printf("%nYour unique array is [%d, %d, %d, %d, %d]", array[0], array[1], array[2], array[3], array[4]);
    }
}
