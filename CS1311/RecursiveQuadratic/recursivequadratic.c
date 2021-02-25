/* C program by Azariel Del Carmen for CS1311 Feb 2021
 * Takes the normal and recursion of a given value to 
 * a fixed function
 */
 
#include <stdio.h>
#include <math.h>

int posInt (void)
{
	int temp = -1; /* initialize temp to store the user integer */
	
	while(temp < 0) /* while temp is less than 0 */
	{ 
		printf("\nPlease type a positive integer: "); /* ask the user for a positive integer */
		scanf("%d", &temp);
	}
	printf("\nYou typed in %d.\n", temp);
	return temp;
}

int recursiveQuadratic(int ruby)
{
	if (ruby == 0) /* if ruby's value is 0 */
	{
		return 4; /* return 4 to the console */
	}
	else
	{
		return (ruby-1)+(6*ruby)+4; /* calculate the recursive quadratic and return the total */
	}
}

void main (void)
{
	int val, result = 0; /* initialize val and result for value storing */
	char runAgain = 'n'; /* initialize runAgain to store a character for the do-while loop */
	
	printf("This program takes a value and outputs it inside 3x^2+7x+4, two ways.\n");
	do
	{
		val = posInt(); /* call posInt and store the returned value to val */
		
		result = (3*pow(val, 2))+(7*val)+4; /* calculate the quadratic value and store it to result */
		printf("\nThe quadratic formula answer with the value of %d is: %d\n", val, result);
		
		result = recursiveQuadratic(val); /* calculate the recursive quadratic and store it to result */
		printf("The recursive formula answer with the value of %d is: %d\n", val, result);
		
		printf("\nDo you want to run the program again? Y/N: "); /* ask the user if they want to run the program again */
		scanf(" %c", &runAgain);
	}
	while (runAgain == 'y' || runAgain == 'Y'); /* continue if runAgain is y or Y, else stop */
}
