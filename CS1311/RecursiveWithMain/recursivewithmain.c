/* C program by Azariel Del Carmen for CS1311 Feb 2021
 * recursion with main - DON'T DO THIS FOR REAL
 * ask for a letter, print it, until z
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 void main (void)
 {
 	char letter, newline; /* holds input, newline char */
 	
 	printf("This program calls main recursively. \n");
 	printf("Please type in a letter (z to end): ");
 	scanf("%c%c", &letter, &newline);
 	printf("You entered %c.\n", letter);
 	
 	if(letter != 'z') /* run until z is input */
 	{
 		main(); /* DON'T DO THIS */
	}
	printf("    after call to main, letter is %c \n", letter);
 }
