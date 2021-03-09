/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * get 5 unique numbers between 1 and 100
 */
 
#include <stdio.h>

/* look for x in array; return 1 if found, 0 if not */
int check_for_unique(int x, int array[])
{
	int i, duplicate = 0;
	
	for (i = 0; i < 5; i++) /* check each element of array for x */
	{
		if (x == array[i])
		{
			duplicate = 1;
		}
	}
	return (duplicate);
}

void main (void)
{
	/* user's, how many, unique=0 if a new member */
	int n = 0, count = 0, unique;	
	int numbers[5] = {0, 0, 0, 0, 0};
	
	printf("Give me 5 unique numbers from 1-100.\n\n");
	while (count < 5) /* get 5 unique values */
	{
		printf("Type in a integer between 1-100:  ");
		scanf("%d", &n);
		printf("You entered %i. \n", n);
		unique = check_for_unique(n, numbers);
		printf("### unique = %i \n", unique);
		if (unique == 0 && n > 0) /* value is OK */
		{
			numbers[count] = n;
			count = count + 1;
		}
	}
	printf("\nThe list is \n");
	for (count = 0; count < 5; count++) /* print each element */
	{
		printf("    %i ", numbers[count]);
	}
}
