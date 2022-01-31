import java.util.Scanner;

/*
Azariel Del Carmen
Java Programming Language
Date: Jan 31
This class is the main class of AutoPolicy
*/

public class LetterGrade {

    public static void main(String[] args) {
        int count = 0; //number of grades entered by the user
        int total = 0; //number of total students

        int aCount = 0;
        int bCount = 0;
        int cCount = 0;
        int dCount = 0;
        int fCount = 0;

        //prompt user for grades
        System.out.printf("%s%n%s%n%s%n%s%n", "Enter the integer grades in range 0-100 for CS2323",
            "Type the end-of-file character to terminate input and see the results",
            "On Linux or macOS, type <command>+D then press enter",
            "On Windows, type <ctrl>+Z then press enter");

        Scanner input = new Scanner(System.in);

        while (input.hasNext()) {
            int currentGrade = input.nextInt();
            count++;
            total = total + currentGrade;
            switch (currentGrade/10) {
                case 10:
                case 9:
                    aCount++;
                    break;
                case 8:
                    bCount++;
                    break;
                case 7:
                    cCount++;
                    break;
                case 6:
                    dCount++;
                    break;
                default:
                    fCount++;
                    break;
            }
        }

        System.out.printf("%s%d%s%d%n", "The average grade in ", count, " grades is ", total / count);
        System.out.printf("%s%d%n", "A: ", aCount);
        System.out.printf("%s%d%n", "B: ", bCount);
        System.out.printf("%s%d%n", "C: ", cCount);
        System.out.printf("%s%d%n", "F: ", dCount);
        System.out.printf("%s%d%n", "F: ", fCount);
    }
}
