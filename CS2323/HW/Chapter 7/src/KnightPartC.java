import java.security.SecureRandom;

public class KnightPartC {
    private static SecureRandom random = new SecureRandom();
    private static int[][] board;

    private static int[][] access = { { 2, 3, 4, 4, 4, 4, 3, 2 },
            { 3, 4, 6, 6, 6, 6, 4, 3 },
            { 4, 6, 8, 8, 8, 8, 6, 4 },
            { 4, 6, 8, 8, 8, 8, 6, 4 },
            { 4, 6, 8, 8, 8, 8, 6, 4 },
            { 4, 6, 8, 8, 8, 8, 6, 4 },
            { 4, 6, 8, 8, 8, 8, 6, 4 },
            { 3, 4, 6, 6, 6, 6, 4, 3 },
    };

    // moves
    private static int[] horizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
    private static int[] vertical = { -1, -2, -2, -1, 1, 2, 2, 1 };

    public static void main(String[] args) {
        board = new int[8][8];
        int currentMove = 0;

        int currentRow = 0;// random.nextInt(8);
        int currentColumn = 0;// random.nextInt(8);
        board[currentRow][currentColumn] = ++currentMove;

        // boolean flag that shows end of the moves
        boolean done = false;

        while (!done) {
            boolean possibleMove = false;
            int minAccess = 100;
            int minRow = -1;
            int minColumn = -1;

            // check all possible moves
            // find the first valid one and move the knight
            for (int i = 0; i < horizontal.length; i++) {
                int testRowIndex = currentRow + vertical[i];
                int testColumnIndex = currentRow + horizontal[i];

                if (valid(testRowIndex, testColumnIndex)) {
                    if (access[testRowIndex][testColumnIndex] < minAccess) {
                        minAccess = access[testRowIndex][testColumnIndex];
                        minRow = testRowIndex;
                        minColumn = testColumnIndex;
                        possibleMove = true;
                    } // else if (access[testRowIndex][testColumnIndex] == minAccess) {
                      // call a method pass testRow and testColumn and return minAccess
                      // call a method pass minRow and minColumn and return minAccess
                      // compare minAccesses from the two method calls
                      // Update the minAccess and minRow & minColumn

                    // }
                }
            }

            if (minRow > -1 && minColumn > -1) {
                currentRow = minRow;
                currentColumn = minColumn;
                board[currentRow][currentColumn] = ++currentMove;
            } else {
                System.out.println("You are stuck. No where to go!");
                done = true;
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

    private static int resolveTie(int row, int column) {
        // return the min access from this position
        return 1;
    }
}
