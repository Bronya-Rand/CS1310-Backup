/* C program by Azariel Del Carmen for CS1311 Jan 2021
 * This program reads text downwards
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void)
{
	char string[80] = "test"; /* input from user */
	int place = 0; /* place in string */
	
	printf("This program prints your input downwards.\n\n");
	printf("Type a phrase to print down: ");
	gets(string);
	printf("You entered \n %s \n and downward is \n", string);
	
	while (string[place] != '\0')
	{
		printf(" %c \n", string[place]);
		place = place + 1;
	}
}