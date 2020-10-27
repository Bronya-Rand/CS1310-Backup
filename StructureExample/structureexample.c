/* C program by Azariel Del Carmen for CS1310 Oct 2002
 * gameplay using structures
 */
 
#include <stdio.h>
#include <string.h>

struct games /* record scores of games */
{ 
	char person1[50]; /* person1 is the winner */
	char person2[50];
	int score;
};
struct games first;

void main (void)
{
	struct games second; /* second record for a game */
	struct games third; /* third game score */
	
	printf("Here are the scores for today's games --- \n\n");
	strcpy(first.person1, "Doc");
	strcpy(first.person2, "Joe");
	first.score = 10000;
	printf("  %s won against %s with a score of %i.  \n", first.person1, first.person2, first.score);
	
	strcpy(second.person1, "Tom");
	strcpy(second.person2, "James");
	second.score = 777;
	printf("  %s won against %s with a score of %i.  \n", second.person1, second.person2, second.score);
	
	strcpy(third.person1, "Yang");
	strcpy(third.person2, "Ruby");
	third.score = 9001;
	printf("  %s won against %s with a score of %i.  \n", third.person1, third.person2, third.score);
}
