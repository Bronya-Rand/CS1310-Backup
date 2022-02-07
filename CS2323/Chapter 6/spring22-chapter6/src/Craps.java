import java.security.SecureRandom;

public class Craps {
    
    private int point;
    //can also define Status as static
    private enum Status{WIN, LOSE, CONTINUE};
    //belongs to each object of the game
    private Status currentStatus;

    private static SecureRandom random = new SecureRandom();

    //constructor
    public Craps() {
        setPoint();
        checkPoint();
    }

    private void setPoint() {
        this.point = rollDice();
    }

    private int rollDice() {
        int die1 = 1 + random.nextInt(6);
        int die2 = 1 + random.nextInt(6);

        return die1 + die2;
    }

    private void checkPoint() {
        if (this.point == 7 || this.point == 11) {
            this.currentStatus = Status.WIN;
            System.out.println("You won!");
        }
        else if (this.point == 2 || this.point == 3 || this.point == 12) {
            this.currentStatus = Status.LOSE;
            System.out.println("You lost!");
        }
        else {
            this.currentStatus = Status.CONTINUE;
            continueMethod();
        }
    }

    private void continueMethod() {
        int currentPoint = rollDice();

        if (currentPoint == this.point) {
            this.currentStatus = Status.WIN;
            System.out.println("You won!");
        }
        else if (currentPoint == 7) {
            this.currentStatus = Status.LOSE;
            System.out.println("You lost!");
        }
        else {
            continueMethod();
        }
    }
}
