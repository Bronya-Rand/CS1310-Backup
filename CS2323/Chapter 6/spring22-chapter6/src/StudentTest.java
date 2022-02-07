public class StudentTest {
    
    public static void main(String[] args) {

        Student stu1 = new Student("0011", "James");
        System.out.println(stu1.toString());

        Student stu2 = new Student("0012", "David");
        Student.setUniName("Harvard");
        System.out.println(stu2.toString());
        System.out.println(stu1.toString());
    }
}
