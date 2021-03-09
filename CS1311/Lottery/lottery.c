/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * This program asks the user for 7 positive numbers from 1-50
 * and generates random numbers, sort them and return them to the user
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInt(void)
{
	int temp = 0;
	while (temp <= 0 || temp > 50)
	{
		printf("Please type a positive integer from 1-50: ");
		scanf("%d", &temp);
	}
	printf("You entered %i.\n", temp);
	return temp;
}

void main (void)
{
	int i, userValues[6], randomValues[6];
	printf("This program asks the user for 7 positive integers from 1-50 and\ngenerates 7 random numbers, sorts the values in bubble sort and\nreturns it to the user.\n\n");
	
	for (i = 0; i <= 6; i++)
	{
		userValues[i] = getInt();
	}
	
	srand(time(NULL)); /* starts the generator with a random number */
	printf("Generating random values, please wait...\n");
	for (i = 0; i <=6; i++)
	{
		randomValues[i] = rand()%50+1;
	}
	printf("Generation completed.\n");
	// TEST ARRAY ENTERING
	for (i = 0; i <= 6; i++)
	{
		printf("U: %i\n", userValues[i]);
		printf("R: %i\n", randomValues[i]);
	}
}