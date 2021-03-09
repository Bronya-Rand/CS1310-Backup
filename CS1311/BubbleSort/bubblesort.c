/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * bubble sort
 */
 
#include <stdio.h>

void print_array (int n, int array[]) /* prints array's items */
{
	int i; /* spot in array */
	
	printf("The list is \n");
	for (i = 0; i < n; i++)
	{
		printf("   %i  ", array[i]);
	}	
}


void main (void)
{
	int list[5] = {77, 66, 22, 33, 11}; /* list to sort */
	int n = 5, i = i, pass = 1, temp, sorted = 1; /* sorted is 1 if true */
	
	printf("This program bubble sorts a list. \n\n");
	printf("\nFor the un-order list - \n");
	print_array(n, list);
	do
	{ /* while list is not sorted */
		sorted = 1; /* assume list is sorted */
		for (i = 0; i < n-1; i++) /* for each adjacent pair */
		{
			if (list[i] > list[i+1]) /* if 1st > 2nd, swap */
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				sorted = 0; /* list was not sorted */
			}
		}
	} while (sorted == 0); /* list is not yet sorted */
	
	printf("\n\nFor the ordered list - \n");
	print_array(n, list);
}