import java.util.Scanner;

public class StringPortionCompare {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Please enter your first string: ");
        String first = input.nextLine();

        System.out.print("Please enter your second string: ");
        String second = input.nextLine();

        int firstRange = -1;
        while (firstRange < 0 || firstRange > first.length()) {
            System.out.printf("From which position do you want to start the comparison in the first string? [Min: 1 | Max: %d]: ", first.length() + 1);
            firstRange = input.nextInt() - 1;
        }

        int secondRange = -1;
        while (secondRange < 0 || secondRange > second.length()) {
            System.out.printf("From which position do you want to start the comparison in the second string? [Min: 1 | Max: %d]: ", second.length() + 1);
            secondRange = input.nextInt() - 1;
        }

        int charAmount = -1;
        while (charAmount < secondRange) {
            System.out.printf("How many characters do you want to compare up to?: ");
            charAmount = input.nextInt();
        }

        if (first.regionMatches(true, firstRange, second, secondRange, charAmount))  {
            System.out.printf("From %d - %d in the 2nd string, both strings matches from first's range from [0 - %d].%n", secondRange, charAmount, firstRange);
        }
        else {
            System.out.printf("From %d - %d in the 2nd string, both strings do not match from first's range from [0 - %d].%n", secondRange, charAmount, firstRange);
        }
    }
}
