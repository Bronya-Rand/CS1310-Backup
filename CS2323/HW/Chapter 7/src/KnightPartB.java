import java.security.SecureRandom;

public class KnightPartB {

    private static SecureRandom random = new SecureRandom();
    private static int[][] board;

    // moves
    private static int[] horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
    private static int[] vertical = { -1, -2, -2, -1, 1, 2, 2, 1 };

    public static void main(String[] args) {
        board = new int[8][8];
        int currentMove = 0;

        int currentRow = random.nextInt(8);
        int currentColumn = random.nextInt(8);
        board[currentRow][currentColumn] = ++currentMove;

        // boolean flag that shows end of the moves
        boolean done = false;

        while (!done) {
            boolean possibleMove = false;

            // check all possible moves
            // find the first valid one and move the knight
            for (int i = 0; i < horizontal.length; i++) {
                int testRowIndex = currentRow + vertical[i];
                int testColumnIndex = currentRow + horizontal[i];

                if (valid(testRowIndex, testColumnIndex)) {
                    currentRow = testRowIndex;
                    currentColumn = testColumnIndex;
                    board[currentRow][currentColumn] = ++currentMove;
                    possibleMove = true;
                    break;
                }
            }

            if (currentMove == 64) {
                System.out.println("You moved the knight all across the board!");
                done = true;
            } else if (!possibleMove) {
                System.out.println("You are stuck. No where to go!");
                done = true;
            }
        }
        printBoard();
    }

    private static boolean valid(int row, int column) {
        if (row < 8 && column < 8 && row > -1 && column > -1) {
            if (board[row][column] == 0) {
                return true;
            }
        }
        return false;
    }

    private static void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(board[i][j] + " ; ");
            }
            System.out.println();
        }
    }
}
