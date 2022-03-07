public class Tictactoe {

    private enum symbol {
        X, O, EMPTY
    };

    private symbol[][] board = new symbol[3][3];
    public boolean win = false;
    public boolean draw = false;
    private int playerID = 1;
    private int moves = 1;

    public Tictactoe() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = symbol.EMPTY;
            }
        }
    }

    private int getXPos(int pos) {
        if (pos < 1 || pos > 9) {
            return -1;
        } else {
            return (pos - 1) / 3;
        }
    }

    private int getYPos(int pos) {
        if (pos < 1 || pos > 9) {
            return -1;
        } else {
            if (pos == 1 || pos == 4 || pos == 7) {
                return 0;
            } else if (pos == 2 || pos == 5 || pos == 8) {
                return 1;
            } else {
                return 2;
            }
        }
    }

    public boolean validateMove(int pos) {
        int x, y;
        x = getXPos(pos);
        y = getYPos(pos);

        if (x != -1 && y != -1) {
            return true;
        }
        return false;
    }

    public void setMove(int pos) {
        boolean valid = validateMove(pos);
        if (!valid) {
            System.out.println("That move is invalid. Please try again.");
        } else {
            int x, y;
            x = getXPos(pos);
            y = getYPos(pos);

            if (board[x][y] != symbol.EMPTY) {
                System.out.println("That space is occupied. Please try again.");
            } else {
                moves++;
                if (playerID == 1) {
                    board[x][y] = symbol.X;
                } else {
                    board[x][y] = symbol.O;
                }

                checkWin(playerID);

                if (win) {
                    System.out.printf("Player %d wins!", playerID);
                } else if (moves == 10) {
                    draw = true;
                    System.out.println("The game is a draw!");
                } else {
                    if (playerID == 1) {
                        playerID++;
                    } else {
                        playerID--;
                    }
                }
            }
        }
    }

    private void checkWin(int playerID) {
        symbol playerSymbol;
        if (playerID == 1) {
            playerSymbol = symbol.X;
        } else {
            playerSymbol = symbol.O;
        }

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol
                    || board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol
                    || board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol
                    || board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol) {
                win = true;
            }
        }
    }

    public int getPlayerID() {
        return playerID;
    }
}
