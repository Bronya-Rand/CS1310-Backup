/* c program by Azariel Del Carmen for CS1311 Mar 2021
 * example of pointer to a function
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_random (void)
{
	printf("A random value is %i.\n", rand());
}

void main (void)
{
	void (*pfunction) (); /* point to function with no inputs or outputs */
	int input, number;
	int (*pfunc2) (int);
	
	printf("This program plays with a pointer to a function.\n\n");
	srand(time(NULL));
	pfunction = print_random;
	printf("From calling directly -- \n  ");
	print_random();
	printf("From the function pointer -- \n  ");
	(*pfunction) ();
	
	pfunc2 = square;
	printf("What integer would you like to square?: ");
	scanf("%d", &input);
	number = (*pfunc2) (input);
	printf ("\n The square of %i is %i.\n\n", number, number)
	
}