/* C program by Azariel Del Carmen for CS1311 Mar 2021 (Futurfying the Date)
 * This program take different college items, their usefulness
 * and cost and outputs them as a list
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* list of college dorm items, cost and usefulness */
struct collegeDormItems
{
	char objectName[50]; /* name of the item */
	int usefulness; /* usefulness of the item */
	double costOfItem; /* cost of the item */
	struct collegeDormItems *next; /* link the list */
};
struct collegeDormItems *head, *element, *last;

char getName(char *itemName)
{
	printf("Please type the name of the item. (Type \"done\" to stop the program): ");
	gets(itemName);
	printf("You typed %s.", itemName);
}

int getInt (void)
{
	int tempInt = -1; /* get into loop to start getting a val */
	
	while(tempInt < 0) /* while temp is less than 0 */
	{ 
		printf("\nPlease type the usefulness of this item to you from 1-10: "); /* ask the user for a positive integer */
		scanf("%d", &tempInt);
	}
	printf("\nYou typed in %i.\n", tempInt);
	return tempInt;
}

double getDouble (void)
{
	double tempDouble = 0.0;
	printf("\nPlease type the cost of this item: "); /* ask the user for a positive integer */
	scanf("%lf", &tempDouble);
	printf("\nYou typed in %.2lf.\n", tempDouble);
	return tempDouble;
}

void add_element(char *name, int rank, double cost) /* put number in the list */
{
	element = malloc(sizeof(struct collegeDormItems));
	strcpy(element->objectName, name);
	element->usefulness = rank;
	element->costOfItem = cost;
	element->next = NULL;
	if (head == NULL)
	{
		head = element; /* first item in list */
	}
	else
	{
		last->next = element; /* hook up new element to list */
	}
	last = element; /* move last to the end of the list */
}

void print_list (void)
{
	int count = 0;
	double sum = 0.0;
	
	element = head;
	printf("\n\n\nYour college purchase list that you have created is:\n");
	while (element != NULL) /* print each item */
	{
		printf("%s", element->objectName);	
		//printf("    %s     %i     %.2lf\n", element->objectName, element->usefulness, element->costOfItem);
		count = count + 1;
		sum = sum + element->costOfItem;
		element=element->next; /* move to next item */
	}
	printf("\n\nYou bought %i items for college and the total cost of all of them is $%.2lf.\n\n", count, sum);
}

void main(void)
{
	char nameOfItem[50]; /* stores the name of the item for the structure */ 
	int rank;
	double cost;
	
	printf("This program take different college items, their usefulness and cost and outputs them as a list.\n\n");
	head = NULL;
	getName(nameOfItem);
	while (strcmp(nameOfItem, "done\0\0") != 0)
	{
		//rank = getInt();
		rank = 1;
		//cost = getDouble();
		cost = 1.0;
		add_element(nameOfItem, rank, cost);
		getName(nameOfItem);
	}
	print_list();
}
 