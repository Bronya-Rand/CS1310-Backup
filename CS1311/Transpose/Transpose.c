/* C program by Azariel Del Carmen for CS1311 Jan 2021
 * This program takes names inputted in a file and 
 * outputs their names downwards
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
#include <string.h>

void main (void)
{
	/* sets up nameCount for name lengths, x and places for for loops*/
	int nameCount = 27, place, x;
	/* sets up in and out for file access */
	FILE *in, *out;
	/* sets up the array for names */
	char names [nameCount][60];
	/* sets up a temp char for reading strings */
	char astring[60];

	printf("This program takes in names from a file and outputs them downwards.\n\n");
	/* opens the files for file access */
	in = fopen("names.txt", "r");
	out = fopen("trans.txt", "w");
	
	/* sets the array to blanks */
	for (x = 0; x <= nameCount; x++)
	{
		for (place = 0; place < 60; place++)
		{
			names[x][place] = ' ';
		}
	}

	printf("Reading data from \"names.txt\". Please wait...\n\n");
	/* begins reading from names.txt and saves it to the array */
	for (x = 0; x <= nameCount; x++)
	{
		/* copies the string to the array */
		fgets(names[x], 60,  in);
	}
	
	printf("Printing to a output file. Please wait...\n\n");
	/* prints name arrays side-ways */
	for (x = 0; x < 60; x++)
	{
		for (place = 0; place <= nameCount; place++)
		{
			/* checks if the character is not a new line and whitespace */
			if (names[place][x] != '\n' && names[place][x] != '\0')
			{
				/* prints character to screen and out file */
				printf(" %c", names[place][x]);
				fprintf(out, " %c", names[place][x]);
			}
			else
			{
				/* prints blank to screen and out file */
				printf("  ", names[place][x]);
				fprintf(out, "  ", names[place][x]);
			}
		}
		/* prints a new line to screen and out file */
		printf("\n");
		fprintf(out, "\n");
	}
	
	/* lets the user know the process is complete and to close the text files */
	printf("\n The process has been completed. \n");
	fclose(in);
	fclose(out);
}
 
