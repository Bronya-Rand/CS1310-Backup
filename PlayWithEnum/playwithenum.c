/* C program by Azariel Del Carmen for CS1310 Oct 2020
 * playing with enumerated data type -- create an on or off 
 */
#include <stdio.h>

void main(void)
{
	enum toggle {off, on}; /* could do a typedef, and later just need toggle to declare a variable variable */
	enum toggle abit = off;
	char move = 'y';
	
	printf("This program toggles a bit as long as you want. \n\n");
	while(move =='y') /* long as the bit is changes */
	{
		printf("\n abit is %i\n", abit);
		printf("Would you like to toggle abit? (y for yes, n for no) ");
		scanf("%c", &move);
		getchar(); /* read newline */
		
		if(abit == on)
		{
			abit = off;
		}
		else
		{
			abit = on;
		}
	}
}
