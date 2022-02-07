public class InitArray {
    
    public static void main(String[] args) {
        int[] arrayExample = new int[10];

        for (int i = 0; i <= 9; i++) {
            System.out.println(arrayExample[i]);
        }

        double[] grades = {12, 100, 67, 56};

        for (int i = 0; i <= grades.length; i++) {
            System.out.println(grades[i]);
        }
    }
}
