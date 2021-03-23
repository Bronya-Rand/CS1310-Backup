/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * mess with input to main
 */
 
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[])
{
	int i = 0;
	
	while (i < argc) /* print each part of argv */
	{
		printf("\n argurment is %i is %s \n", i, argv[i]);
		i = i + 1;
	}
	getchar();
}