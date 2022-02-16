public class GradeBookApp {
    
    public static void main(String[] args) {
        double[] grades = {100, 89, 78, 10, 55};
        GradeBook cs2323 = new GradeBook(grades);

        System.out.println(cs2323.calcAverage());
    }
}
