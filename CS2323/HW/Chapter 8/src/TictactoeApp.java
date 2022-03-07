import java.util.Scanner;

public class TictactoeApp {
    
    public static void main(String[] args) {
        Tictactoe gameOne = new Tictactoe();
        int player, pos;
        Scanner input = new Scanner(System.in);

        do {
            player = gameOne.getPlayerID();
            System.out.printf("Player %d, please select a position from 1-9: ", player);
            pos = input.nextInt();
            gameOne.setMove(pos);
        } while (!gameOne.win && !gameOne.draw);
    }
}
