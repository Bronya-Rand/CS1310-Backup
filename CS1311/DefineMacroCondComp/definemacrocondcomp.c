/* C program by Azariel Del Carmen for CS1311 Apr 2021
 * example define, macro and conditional compilation
 */
#include <stdio.h>
#define DEBUGON 9 /* change to 9 later */
#define Cube(z) z*z*z

void main (void)
{
	#ifdef DEBUGON
		printf("DEBUGON is defined. \n\n");
	#endif
	#if DEBUGON == 9
		printf("DEBUGON has the value nine (9). \n\n");
	#endif
}