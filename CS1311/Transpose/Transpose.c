/* C program by Azariel Del Carmen for CS1311 Jan 2021
 * This program takes names inputted in a file and 
 * outputs their names downwards
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (void)
{
	/* sets up nameCount for name lengths, x for for loops and places */
	int nameCount = 15, place = 0, x;
	/* sets up in and out for file access */
	FILE *in, *out;
	/* sets up the array for names */
	char names [nameCount][60];
	/* sets up a temp char for reading strings */
	char astring[60];
	
	printf("This program takes in names from a file and outputs them downwards.\n\n");
	/* opens the files for file access */
	in = fopen("names.txt", "r");
	out = fopen("result.txt", "w");
	
	/* begins reading from names.txt and saves it to the arry using astring */
	printf("Reading data from \"names.txt\". Please wait...\n\n");
	for (x = 0; x <= nameCount; x++)
	{
		/* copies the string from the temp char to the array */
		strcpy(names[x], fgets(astring, 60,  in));
	}
	
	/* prints name arrays side-ways TO-DO: Separate Sections */
	printf("Printing to a output file. Please wait...\n\n");
	for (x = 0; x <= nameCount; x++)
	{
		while (names[x][place] != '\0\0')
		{
			/* prints the array to the resulting text file */
			fprintf(out, " %c ", names[x][place]);
			place = place + 1;
		}
		/* reset counter */
		place = 0;
		/* prints the array to the resulting text file */
		//fprintf(out, "%s \n", strtok(names[x], "\n"));
	}
	
	/* lets the user know the process is complete and to close the text files */
	printf("Process Complete. \n");
	fclose(in);
	fclose(out);
}
 