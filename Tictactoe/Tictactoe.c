/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * Allows 2 players to play tic-tac-toe in C
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
/* sets up the tic-tac-toe box length and width */
char ttt[3][3];
char player = 'X';
char cont = 'N';
int moves = 1;
int xPos, yPos, digit, win = 0;

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
	int x;
	int temp = 0;
	/* column win */
	for(x = 0; x < 3; x++)
	{
		if(ttt[x][0] == player && ttt[x][1] == player && ttt[x][2] == player || ttt[0][x] == player && ttt[1][x] == player && ttt[2][x] == player 
		|| ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player || ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player)
		{
			temp = 1;
		}
	}
	return temp;
}

void resetArray(void)
{
	int x, y;
	for(x = 0; x < 3; x++)
	{
		for(y = 0; y < 3; y++)
		{
			ttt[x][y] = ' ';
		}
	}
	moves = 1;
}

void main(void)
{
	printf("This program re-creates tic-tac-toe in C.\n\n");
	do
	{
		do
		{
			printBoard();
			digit = getValue();
			switch (digit)
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
			if(ttt[xPos][yPos] == 'X' || ttt[xPos][yPos] == 'O')
			{
				printf("A player already occupies this slot. Try again.\n");
			}
			else
			{
				ttt[xPos][yPos] = player;
				win = checkWin();
				if (win == 0)
				{	
					if (player == 'X')
					{
						player = 'O';
					}
					else
					{
						player = 'X';
					}
					moves++;
				}
				else
				{
					moves = 10;
				}
			}
			
		} while (moves < 10);
		if (win == 1)
		{
			printf("Player %c wins!", player);
		}
		else
		{
			printf("A tie happened. No one wins.");
		}
		resetArray();
		printf("\n\nDo you want to play again? (Y/N): ");
		scanf(" %c", &cont);
	} while(cont == 'Y' || cont == 'y');
}
