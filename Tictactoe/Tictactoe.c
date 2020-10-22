/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * This program re-creates Tic-tac-toe in C with 2 human players
 * 
 * ||||||||||||||||||||||||\_|||__|||||||||
 * |||||||||||||||||||S\_\@\_||___|||||||||
 * |||||||||||||||||SS@S\\SS__\__||||||||||
 * ||||||||||||||||S@@@@\_\S_\S_|||||||||||
 * ||||||||||||||\S@@SSSSSSSSSSSS\|||||||||
 * |||||||||||||\S@SSSSSSSSSS@S@@@SS|||||||
 * |||||||||||||S@SS@@@@@@@@@@@SSS@@S||||||
 * ||||||||||||SSSS@@@@@@@@@@@SSSSS@S\|||||
 * |||||||||||SSSSS@@@@@@@@@@SSSSSSSS\|||||
 * |||||||||||SSS@@@@@@@@@@@SSSSSSSS@S|||||
 * ||||||||||SSS@@@@@@@@@@@SSS@SSS@@@S\||||
 * ||||||||||SS@@@@@@@@@@SSSS@@\S@@@@@S_|||
 * |||||||||SS@@@@@@@@@@SSS@@@SSS@@@@SS\|||
 * ||||||||_S@@@@@@@@@SSSS@@S\\S@@@@SSS\|||
 * ||||||||SS@@@@@@SSSSS@@SS\\S@@@@@S\S\_||
 * |||||||SSS@SSSSSSSSSSS\\\SSS@@@@@S\@S_||
 * ||||||S@SSSS\SSSSS\\\\\S@@SS@@@@@S\@S_||
 * |||||S@@S\\\\\\\\\\SSSS@@@@S@@@@SS\S\|||
 * ||||S@@@S\__\___SS@@@@SSSSSSS@@@S\\S\|||
 * ||||S@@@S\\S\_\S@@@@@@SSSS@SS@@@S\\S\|||
 * |||\S@@SSSSSSSS@@@@@@@\||_\SSS@S\\\S\|||
 * |||\SSS\SSSSSS@@@@@@@@\__\__SSSS\\SS_|||
 * |||_SS\\SSSSSSSS@S@@@@S\\\@_\SS\\\S\||||
 * |||\S@@SSSSSSSSSSSSSSSSSSSSS@\\\\\S\||||
 * ||S@@@@SSS@SSS@SS@SSSSSSSSS@S\\\\\\_||||
 * |S@@@@@S\\@@@@@SS@@SSSSSSS@S\\\\\\_|||||
 * |S@@@@S@\\S@@@@@@@@@@SSSSSS\\\SSS\||||||
 * \S@@@SSS_\S@@@S@@@@@@@@SSS\\\SSS\_||||||
 * S@@@SSSS_S@S@@@SS@@@@@@S\\\SSSS\||||||||
 * S@SSSSS@S@@SS@@@@@@@@@S\\\\\\\\_||||||||
 * SSSSSSS@@@@@SS@@@@@SS\\__\\\\\_|||||||||
 * @@@@@SS@@@@@@SSSSS\\\__||_\_||||||||||||
 * @@@SSSSS@@@@@S\\\\\\__|||||||||||||||||| 
 */
 
#include <stdio.h>
char ttt[3][3]; /* sets the tic-tac-toe box */
char player = 'X'; /* current player character (X/O) */
char cont = 'N'; /* continue character for starting a new game */
int moves = 1; /* moves of the game */
int xPos, yPos, digit, win = 0; /* position of the row/column, position number and win condition */

/* obtains the integer the user inputs */
int getValue (void)
{
	int temp = 0; /* gets the user's value */
	
	while(temp < 1 || temp > 9)
	{ /* asks for a positive integer */
		printf("\nPlease type a position from 1-9: ");
		scanf("%d", &temp);
	}
	printf("\nYou typed in %d.\n", temp); /* returns their inputted value */
	return temp; /* returns value to variable */
}

void printBoard (void)
{
	/* guide */
	printf("\nGuide: \n");
	printf("    1  |  2  |  3  \n");
	printf("  ------+-----+------\n");
	printf("    4  |  5  |  6  \n");
	printf("  ------+-----+------\n");
	printf("    7  |  8  |  9  \n\n");
	/* actual board */
	printf("Move %d (Player %c)\n", moves, player);
	printf("    %c  |  %c  |  %c  \n", ttt[0][0], ttt[0][1], ttt[0][2]);
	printf("  -----+-----+------\n");
	printf("    %c  |  %c  |  %c  \n", ttt[1][0], ttt[1][1], ttt[1][2]);
	printf("  -----+-----+------\n");
	printf("    %c  |  %c  |  %c  \n", ttt[2][0], ttt[2][1], ttt[2][2]);
}

int checkWin(void)
{
	int x; /* initializes x for the for loop */
	int temp = 0; /* sets temp to 0 as if the game wasn't won */
	for(x = 0; x < 3; x++) /* controls position if different slots for row/column wins */
	{
		/* checks if the player got a row, column, diagonal, or reverse-diagonal win */
		if(ttt[x][0] == player && ttt[x][1] == player && ttt[x][2] == player || ttt[0][x] == player && ttt[1][x] == player && ttt[2][x] == player 
		|| ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player || ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player)
		{
			temp = 1; /* sets temp to 1 as if the game was won */
		}
	}
	return temp; /* returns set temp value to win */
}

void resetArray(void)
{
	int x, y;
	for(x = 0; x < 3; x++) /* loops x position for reset */
	{
		for(y = 0; y < 3; y++) /* loops y position for reset */
		{
			ttt[x][y] = ' '; /* makes the row/column given a no character value */
		}
	}
	moves = 1; /* resets moves to 1 */
}

void main(void)
{
	printf("This program re-creates tic-tac-toe in C.\n");
	printf("Instructions: Enter a position from 1-9 and try to get 3 X's or O's\nacross, sideways, diagonal or horizontal.\n");
	/* starts the game and resets if the user 
	wants to play again */
	do
	{
		/* starts the game by drawing borders, getting a position
		checks, placement, and increasing movement/switch players */
		do
		{
			printBoard(); /* prints the board */
			digit = getValue(); /* gets the position for X/O placement */
			switch (digit) /* switch that outputs the row/column of the position given */
			{
				case 1:
		            xPos = 0;
		            yPos = 0;
		            break;
		        case 2:
		            xPos = 0;
		            yPos = 1;
		            break;
		        case 3:
		            xPos = 0;
		            yPos = 2;
		            break;
		        case 4:
		            xPos = 1;
		            yPos = 0;
		            break;
		        case 5:
		            xPos = 1;
		            yPos = 1;
		            break;
		        case 6:
		            xPos = 1;
		            yPos = 2;
		            break;
		        case 7:
		            xPos = 2;
		            yPos = 0;
		            break;
		        case 8:
		            xPos = 2;
		            yPos = 1;
		            break;
		        case 9:
		            xPos = 2;
		            yPos = 2;
		            break;
			}
			/* checks if the space is already has a X or O */
			if(ttt[xPos][yPos] == 'X' || ttt[xPos][yPos] == 'O')
			{
				printf("A player already occupies this slot. Try again.\n"); /* returns that the spot is occupied */
			}
			else
			{
				ttt[xPos][yPos] = player; /* sets row/column to the player's char symbol */
				win = checkWin(); /* check if the player won based off tic-tac-toe win rules */
				if (win == 0) /* if no one has yet won, switch player symbols */
				{	
					if (player == 'X')
					{
						player = 'O';
					}
					else
					{
						player = 'X';
					}
					moves++; /* increase movement turns over time */
				}
				else
				{
					moves = 10; /* make moves 10 to end the do-while */
				}
			}
			
		} while (moves < 10); /* keep doing the do until moves is 10 */
		if (win == 1) /* checks if the game is won */
		{
			printf("Player %c wins!", player); /* outputs current player won the game */
		}
		else
		{
			printf("A tie happened. No one wins."); /* outputs a tie if there is no winner */
		}
		resetArray(); /* resets the char array and move count for a new game */
		printf("\n\nDo you want to play again? (Y/N): "); /* asks if the user wants to play again */
		scanf(" %c", &cont); /* returns input as cont */
	} while(cont == 'Y' || cont == 'y'); /* continue do until cont is not Y or y */
}
