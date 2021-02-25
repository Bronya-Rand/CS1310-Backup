
#include <stdio.h>
#include <stdlib.h>

/* list of positive integers */
struct intlist
{ 
	int num;
	struct intlist *ptr;
};
struct intlist *head, *element, *last;

int get_input (void)
{
	int n = -1; /* get into loop to start getting a val */
	
	while(n < 0) /* while temp is less than 0 */
	{ 
		printf("\nPlease type a positive integer or 0 to stop: "); /* ask the user for a positive integer */
		scanf("%d", &n);
	}
	printf("\nYou typed in %i.\n", n);
	return n;
}

void add_element(int number) /* put number in the list */
{
	element = malloc(sizeof(struct intlist));
	element->num = number;
	element->ptr = NULL;
	if (head == NULL)
	{
		head = element; /* first item in list */
	}
	else
	{
		last->ptr = element; /* hook up new element to list */
	}
	last = element; /* move last to the end of the list */
}

void print_list (void)
{
	int count = 0, sum = 0;
	
	element = head;
	printf("\n\n\nThe list you created is \n");
	while (element != NULL) /* print each item */
	{
		printf("    %i \n", element->num);
		count = count + 1;
		sum = sum + element->num;
		element=element->ptr; /* move to next item */
	}
	printf("\n\n There are %i items and they sum up to %i.\n\n", count, sum);
}

void main (void)
{
	int input = -1; /* user positive val; 0 when done */
	
	printf("This program creates and prints a list of integers. \n");
	head = NULL; /* start with an empty list */
	input = get_input();
	while (input != 0)
	{
		add_element(input);
		input = get_input();
	}
	print_list();
}