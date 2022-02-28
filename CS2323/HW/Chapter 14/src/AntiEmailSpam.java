import java.util.Scanner;

public class AntiEmailSpam {

    public static void main(String[] args) {
        String spam[] = { "$$$", "100% free", "Act", "Affordable", "$$$", "Amazing", "Double",
                "Earn", "Boost", "Eliminate", "Free", "Gift", "Offer", "Time", "!!!", "Apply",
                "Now", "Buy", "Direct", "Call", "Dial", "Reply", "Clearance", "Today", "Don't",
                "Reduced", "Discount", "Expire", "Get", "Gone" };
        int spamScore = 0;

        Scanner input = new Scanner(System.in);
        System.out.print("Type in some email content to check for spam: ");
        String contents = input.nextLine();
        String splitContents[] = contents.split(" ");

        for (int i = 0; i < splitContents.length; i++) {
            for (int j = 0; j < spam.length; j++) {
                if (spam[j].toLowerCase().compareTo(splitContents[i]) == 0) {
                    spamScore++;
                }
            }
        }

        double spamPercent = (spamScore / 30.0) * 100.0;
        System.out.printf("Based off the contents of this email, this email is possibly %.1f%% spam. (%d of 30 hits)",
                spamPercent,
                spamScore);
    }
}
