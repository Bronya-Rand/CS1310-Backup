/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * inputs.c
 * argurments to main and an enum example
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum test {no,yes};
enum test testing = no; /* if yes, print address */

void main (int argc, char *argv[])
{
	int i = 0; /* loop counter */
	
	while (i <= argc) /* print all words in command line */
	{
		printf("   element %i is %s \n", i, argv[i]);
		i = i + 1;
	}
	if (argc > 1 && strcmp(argv[1], "debug") == 0)
	{
		printf("\n*** more information i=%i argc=%d \n", i, argc);
		testing = yes;
	}
	if (argv[1] != NULL)
	{
		printf("\n first parameter=%s as integer=%i \n", argv[1], atoi(argv[1]));
	}
	if (testing == yes)
	{
		printf("\n*** in debug mode since testing is yes \n");
	}
	
	getche(); /* for exe window to stay open */
}