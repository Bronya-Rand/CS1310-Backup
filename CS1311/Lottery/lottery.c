/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * This program asks the user for 7 positive numbers from 1-50
 * and generates random numbers, sorts them and return them to the user
 * while returning any matching numbers from the random generation.
 *
 * ||||||SSS\\\\\\\\SS||
 * ||||SS\\`````````\S||
 * ||SS\````````````\SS|
 * |SS\``````````````\SS
 * |S\\\\\\\\\\\``````\S
 * S\\SSSSSSSSS\SSS\```S
 * S\SSSSSSSSS\\SSSS\``\
 * \\SSS\SSS\\SS\SSS\``\
 * \\S\\\\\\\SS\\\SSS``\
 * \\S\\\`\SSSS`__\SS`\S
 * S\S\\\\SSSSS\\\\\\`\S
 * S\\\\\\SSSSSS\\\\`\S|
 * SSS\\\\S\\SSS\\\\SS||
 * |SSS\\\\\\\\\\``SS|||
 * ||||SS\_____\\``SS|||
 * |||||S`|\\`|\S\`SS|||
 * |||||S_|``_|`S\`\S|||
 * ||||S\`\SS\``S\\SS|||
 * ||SS\\\\\S\\``SSS||||
 * ||S\_|`\\\\\_`S||||||
 * ||SS\__``|_\`SS||||||
 * |||SSSS``\\`\S|||||||
 * ||||||S\`\S\\S|||||||
 * ||||||SS\SSS\S|||||||
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[])
{
	int i;
	
	for (i = 0; i <= 6; i++)
	{
		printf("  %i  ", array[i]);
	}
}

void bubbleSort(int array[])
{
	/* store array values, start position, end position of array, array is sorted */
	int temp, start, length = 7, sorted = 1;
	
	do
	{
		sorted = 1; /* assume list is sorted */
		for (start = 0; start < length - 1; start++)
		{
			if (array[start] > array[start + 1])
			{
				temp = array[start];
				array[start] = array[start + 1];
				array[start + 1] = temp;
				sorted = 0; /* list was not sorted */
			}
		}
	} while (sorted == 0); /* list is not sorted */
}

int is_unique(int val, int array[])
{
	int i, duplicate = 0;
	
	for (i = 0; i < 7; i++) /* check each element of array for x */
	{
		if (val == array[i])
		{
			duplicate = 1;
		}
	}
	return (duplicate);
}

void main (void)
{
	int input, unique, count, userValues[7] = {0, 0, 0, 0, 0, 0, 0}, randomValues[7] = {0, 0, 0, 0, 0, 0, 0}, matches = 0;
	printf("This program asks you for 7 numbers from 1-50\ngenerates 7 random numbers, returns your and the computers numbers," 
	"sorts them via bubble sort and\nreturns them and any matching numbers found between them.\n\n");
	
	while (count < 7) /* get 7 unique values */
	{
		printf("Enter a number between 1-50:  ");
		scanf("%d", &input);
		unique = is_unique(input, userValues); /* check if value is unique in array */
		if (unique == 0) /* value is unique */
		{
			if (input > 0 && input <= 50)  /* value is valid */
			{
				printf("You entered %i. \n\n", input);
				userValues[count] = input; /* sets spot in array to typed value */
				count = count + 1; /* go to next array spot */
			}
			else
			{
				printf("Invalid Number. Please type in another number.\n\n");
			}
		}
		else
		{
			if (input > 0 && input <= 50) /* value is valid */
			{
				printf("You already used %i. Please type in another number.\n\n", input);
			}
			else
			{
				printf("Invalid Number. Please typen in another number.\n\n");
			}
		}
	}
	count = 0; /* resets count to 0 */
	srand(time(NULL)); /* starts the generator with a random pseudo-number */
	printf("Generating random numbers, please wait...\n");
	while (count < 7)
	{
		input = rand()%50+1; /* generate a random number from 1-50 */
		unique = is_unique(input, randomValues); /* check if value is unique in array */
		if (unique == 0) /* value is OK */
		{
			randomValues[count] = input; /* sets spot in array to random value */
			count = count + 1; /* go to next array spot */
		}
	}
	printf("Generation completed.\n\n");
	// TEST ARRAY ENTERING
	printf("You inputted\n");
	printArray(userValues);
	printf("\nAnd sorted is\n");
	bubbleSort(userValues);
	printArray(userValues);
	printf("\n\nThe computer generated\n");
	printArray(randomValues);
	printf("\nAnd sorted is\n");
	bubbleSort(randomValues);
	printArray(randomValues);
	printf("\n\nYour matching numbers are\n");
	for (input = 0; input <= 6; input++)
	{
		for (count = 0; count <= 6; count++)
		{
			if (userValues[input] == randomValues[count])
			{
				printf("  %i  ", userValues[input]);
				matches = matches + 1;
			}
		}
	}
	if (matches == 0)
	{
		printf("No Matching Numbers Found.");
	}
	printf("\n\nYou matched %i out of 7 numbers.\n", matches);
}
