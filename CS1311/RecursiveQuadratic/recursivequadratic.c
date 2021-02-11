/* C program by Azariel Del Carmen for CS1311 Feb 2021
 * Takes the normal and recursion of a given value to 
 * a fixed function
 */
 
#include <stdio.h>
#include <math.h>

int posInt (void)
{
	int temp = -1;
	
	while(temp < 0)
	{ 
		printf("\nPlease type a positive integer: ");
		scanf("%d", &temp);
	}
	printf("\nYou typed in %d.\n", temp);
	return temp;
}

int recursiveQuadratic(int ruby)
{
	if (ruby == 0)
	{
		return 4;
	}
	else
	{
		return (ruby-1)+(6*ruby)+4;
	}
}

void main (void)
{
	int val, result = 0;
	char runAgain = 'n';
	
	printf("This program takes a given value and outputs a fixed function with the value in two ways.\n\n");
	do
	{
		val = posInt();
		
		result = (3*pow(val, 2))+(7*val)+4;
		printf("\nThe quadratic formula answer with the value of %d is: %d\n", val, result);
		
		result = recursiveQuadratic(val);
		printf("The recursive formula answer with the value of %d is: %d\n", val, result);
		
		printf("\nDo you want to run the program again? Y/N: ");
		scanf(" %c", &runAgain);
	}
	while (runAgain == 'y' || runAgain == 'Y');
}
