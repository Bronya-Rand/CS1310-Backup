/* C Program by Azariel Del Carmen for CS1311 Mar 2021
 * binary search of a integer array
 */
 
#include <stdio.h>
#include <math.h>
#define findvalue 55 /* try 40, 5, 2, 80, 90 100 */
#define number_of_items 10

void main (void)
{
	int scores[number_of_items] = /* array to search */
		{3, 5, 7, 10, 20, 40, 50, 70, 80, 99};
	int current = 0, min = 0, max = 9; /* indexes */
	int findme = findvalue;
	int found = -1, count=0; /* found is the spot in scores */
	
	while(found == -1 && min != max && count < 10)
	{
		count = count + 1;
		if (current == max -1) /* check end of list */
		{
			current = max;
		}
		else
		{
			current = (min + max)/2; /* middle of list */
		}
		printf("*** count = %i, min = %i, current = %i, max = %i \n", count, min, current, max);
		
		if (scores[current] == findme) /* found it */
		{
			found = current;
		}
		else
		{
			if (findme < scores[current]) /* search the top/left side */
			{
				max = current;
			}
			else /* search right/bottom half */
			{
				min = current;
			}
		}
	}
	if (found == -1)
	{
		printf("\n\n Element %i was not found in scores. \n", findme);
	}
	else
	{
		printf("\n\n Element %i was found in spot %i", findme, found);
	}
}