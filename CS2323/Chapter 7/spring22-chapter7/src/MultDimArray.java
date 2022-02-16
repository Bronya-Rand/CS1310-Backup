public class MultDimArray {

    public static void main(String[] args) {
        int[][] array1 = {{1,2,3}, {4,5,6}};
        int[][] array2 = {{1,2,3}, {4}, {5,6}};

        int[][] array3 = new int[3][];

        array3[0] = new int[3];
        array3[1] = new int[1];
        array3[2] = new int[2];

        iterateArray(array1);
        iterateArray(array2);
        iterateArray(array3);
    }

    //helper method
    public static void iterateArray(int[][] array) {
        for (int row = 0; row < array.length; row++) {
            for (int column = 0; column < array[row].length; column++) {
                System.out.printf("%d ", array[row][column]);
            }
            System.out.println();
        }
    }
}