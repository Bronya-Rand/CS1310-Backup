public class PassArray {
    
    public static void main(String[] args) {
        int[] array1 = {1,2,3,4,5};

        for (int value : array1) {
            System.out.println(value);
        }
        modifyArray(array1);

        for (int value : array1) {
            System.out.println(value);
        }

        modifyValue(array1[0]);

        for (int value : array1) {
            System.out.println(value);
        }
    }

    public static void modifyArray(int array[]) {
        array[0] = 10;
    }

    private static void modifyValue(int value) {
        value = 20;
    }
}
