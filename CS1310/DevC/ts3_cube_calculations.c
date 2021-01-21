/* ==========================================================================
   Troubleshooting Practice #3
   Description:  This program asks the user for the dimensions of a cube.  It
   will then calculate either the volume, total surface area, or the perimeter
   around the cube based on what the user asks for.
             
       Author:  Scott Raymond
         Date:  29 Aug 2020
	 Language:  C 
    For Class:  CS1310, Programming I 
===========================================================================*/
#include <stdio.h>

void main(void)
{
	int length;      /* holds the cubes length in inches */
	int width;       /* holds the cubes width in inches  */
	int height;      /* holds the cubes height in inches */
	char choice;     /* holds the users selections       */
	
	printf("This program will calculate cube geometry.\n\n");
	
	printf("Enter the cubes length in inches: ");
	scanf("%d", &length);
	printf("Enter the cubes width in inches: ");
	scanf("%d", &width);
	printf("Enter the cubes height in inches: ");
	scanf("%d", &height);
	printf("You entered a %d X %d X %d cube.\n\n", length, width, height);
	
	getchar();  /* captures the newline character in the buffer */

	/* display a menu for the user to select from, and get selection */
	printf("Which of the following calculation would you like done:\n");
	printf("\tP - The perimeter around the cube.\n");
	printf("\tS - The total surface area of the cube.\n");
	printf("\tV - The volume of the cube.\n");
	printf("\nSelect P, S or V: ");	
	scanf("%c", &choice);
	
	/* switch on the choice and make the calculations */
	switch (choice)
	{
		case 'p':
			printf("\nThe perimeter around the cube is: %d inches.\n", 
			       (length + width) * 2);
			break;
		case 'P':
			printf("\nThe perimeter around the cube is: %d inches.\n", 
			       (length + width) * 2);
			break;
		case 's':
			printf("\nThe surface area of the cube is: %d sq inches.\n",
			       ((length*width)+(length*height)+(width*height))*2);
			break;
		case 'S':
			printf("\nThe surface area of the cube is: %d sq inches.\n",
			       ((length*width)+(length*height)+(width*height))*2);
			break;
		case 'v':
			printf("\nThe volume of the cube is %d cubic inches.\n",
			       length * width * height);
			break;
		case 'V':
			printf("\nThe volume of the cube is %d cubic inches.\n",
			       length * width * height);
			break;
		default:
			printf("That was an invalid selection.\n");
	}

}
