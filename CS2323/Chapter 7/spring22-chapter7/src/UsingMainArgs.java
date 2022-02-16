public class UsingMainArgs {

    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("I am looking for three input arguments!");
        }
        int arrayLength = Integer.parseInt(args[0]);
        int initialValue = Integer.parseInt(args[1]);
        int increment = Integer.parseInt(args[2]);

        int[] array1 = new int[arrayLength];
        array1[0] = initialValue;

        for (int i = 1; i < arrayLength; i++) {
            array1[i] = array1[i-1] + increment;
        }

        for (int value : array1) {
            System.out.println(value);
        }
    }
}