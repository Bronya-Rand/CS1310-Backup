/* C program by Azariel Del Carmen for CS1311 Feb 2021
 * linked list of things I want
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
	/* holds info about my favorite characters */
	char name[50];
	double value; /* in rank */
	struct item *next;
};
struct item *start, *ptemp, *current; /* places into items */

void main (void)
{
	printf("This program shows things I want. \n\n");
	
	current = malloc(sizeof(struct item));
	strcpy(current->name, "Weiss Schnee");
	current->value = 1;
	current->next = NULL; /* point to last complete item */
	ptemp = current;
	start = current;
	
	current = malloc(sizeof(struct item));
	strcpy(current->name, "Monika");
	current->value = 2;
	current->next = NULL; /* point to last complete item */
	ptemp = current;
	start = current;
	
	current = malloc(sizeof(struct item));
	strcpy(current->name, "D. Va");
	current->value = 3;
	current->next = NULL; /* point to last complete item */
	ptemp = current;
	start = current;
	
	
	current = start;
	printf("\n  ITEM NAME  \t RANK  \n");
	while (current != NULL) /* print each item */
	{
		printf(" %-20s   %.2lf \n", current->name, current->value);
		current = current->next;
	}
}
