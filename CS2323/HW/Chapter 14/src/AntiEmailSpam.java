import java.util.Scanner;

public class AntiEmailSpam {
    
    public static void main(String[] args) {
        String spam[] = {"$$$", "100% free", "Act Now", "Affordable", "$$$", "Amazing stuff", "Double your income", "Earn $", "Earn extra cash", "Eliminate debt",
        "Free", "Free gift", "Limited time offer", "Make $", "!!!", "Apply online", "Apply now", "Buy", "Buy direct", "Call",
        "Call now", "Call here", "Clearance", "Do it today", "Don't delete", "Drastically reduced", "Exclusive deal", "Expire", "Get", "Get it now"};
        int spamScore = 0;

        Scanner input = new Scanner(System.in);
        System.out.print("Type in some email content to check for spam: ");
        String contents = input.nextLine();
        String splitContents[] = contents.split(" ");

        for (int i = 0; i < splitContents.length; i++) {
            for (int j = 0; j < spam.length; j++) {
                if (spam[j].compareTo(splitContents[i]) == 0) {
                    spamScore++;
                }
            }
        }

        double spamPercent = (spamScore / 30.0) * 100.0;
        System.out.printf("Based off the contents of this email, this email is %.2f% spam. (%d/30 hits)", spamPercent, spamScore);
    }
}
