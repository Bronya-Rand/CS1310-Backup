// Fig. 7.2: InitArray.java
// Initializing the elements of an array to default values of zero.

public class InitArray {

    public static void main(String[] args) {
        int arraySize = 10;
        // declare variable array and initialize it with an array object
        if (args.length > 1) {
            System.out.println("Too many argurments were given. Only 1 argurment is needed.");
        }
        else if (args.length == 1) {
            arraySize = Integer.parseInt(args[0]);
        }
        int[] array = new int[arraySize];

        System.out.printf("%s%8s%n", "Index", "Value"); // column headings

        // output each array element's value
        for (int counter = 0; counter < array.length; counter++) {
            System.out.printf("%5d%8d%n", counter, array[counter]);
        }
    }
}