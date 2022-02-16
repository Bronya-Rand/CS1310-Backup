
public class Course {

    public static void main(String[] args) {
        ArrayList<String> students = new ArrayList<>();
        System.out.println("Initial size is " + students.size())

        students.add("Ian");
        students.add("Alin");
        students.add("Whitley");

        System.out.println(students.get(2));

        students.remove(2);
        System.out.println("New Size: " + students.size());
    }
}