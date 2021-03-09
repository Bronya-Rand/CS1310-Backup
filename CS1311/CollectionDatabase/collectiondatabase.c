/* C program by Azariel Del Carmen for CS1311 Mar 2021 (Futurfying the Date)
 * This program take different college items, their usefulness to the user
 * and cost and outputs them as a list.
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

/* list of college dorm items, cost and usefulness */
struct collegeDormItems
{
	char objectName[50]; /* name of the item */
	int usefulness; /* usefulness of the item */
	double costOfItem; /* cost of the item */
	struct collegeDormItems *next; /* link the list */
};
struct collegeDormItems *head, *element, *last;

/* obtains the user's item name */
char* getName(char *itemName)
{
	while (strcmp(itemName, "") == 0) /* itemName is not blank */
	{
		printf("Please type the name of the item. (Type \"done\" to stop the program): "); /* asks the user for the item name */
		gets(itemName); /* saves the input to itemName */
	}
	printf("\nYou typed in %s.", itemName);
}
	
/* obtains the user's usefulness value of the item. */
int getInt (void)
{
	int tempInt = -1; /* get into loop to start getting a val */
	
	while(tempInt < 0 || tempInt > 10) /* temp is not less than 0 or greater than 10 */
	{ 
		printf("\nPlease type the usefulness of this item to you from 1-10: "); /* ask the user for a positive integer from 1-10 */
		scanf("%i", &tempInt); /* saves the input to tempInt */
	}
	printf("\nYou typed in %i.\n", tempInt);
	return tempInt; /* returns it back to the variable it was called on */
}

/* obtains the cost the user of the item. */
double getDouble (void)
{
	double tempDouble = -1.0; /* get into loop to start getting a val */
	while(tempDouble < 0.0) /* temp is not less than 0.0 */
	{
		printf("\nPlease type the cost of this item: "); /* ask the user for a positive long float */
		scanf("%lf", &tempDouble); /* saves the input to tempDouble */
	}
	printf("\nYou typed in %.2lf.\n", tempDouble);
	return tempDouble; /* returns it back to the variable it was called on */
}

/* adds the name, usefulness, and cost of the item to the structure */
void add_element(char *name, int rank, double cost) /* defines name as a char, rank as a int, and cost as a double to store values */
{
	element = malloc(sizeof(struct collegeDormItems)); /* gets the size of the structure */
	strcpy(element->objectName, name); /* copies the name of the item to objectName in the structure */
	element->usefulness = rank; /* assigns rank into usefulness in the structure */
	element->costOfItem = cost; /* assigns cost into costOfItem in the structure */
	element->next = NULL; /* assigns next with NULL */
	if (head == NULL) /* if head is not NULL */
	{
		head = element; /* assigns head to the first item in list */
	}
	else
	{
		last->next = element; /*adds a new element to the list */
	}
	last = element; /* assigns last to the end of the list */
}

/* prints the list of items the user bought to the console */
void print_list (void)
{
	int count = 0; /* stores how many items the user bought */
	double sum = 0.0; /* stores the cost of all the items the user bought */
	
	element = head; /* assigns element as head */
	printf("\n\nYour college purchase list that you have created is:\n\n");
	printf("\tItem | Usefulness | Cost \n");
	printf("\t---------------------------\n");
	while (element != NULL) /* element hasn't reached the end */
	{
		printf("\t%s     %i\t   $%.2lf\n", element->objectName, element->usefulness, element->costOfItem); /* prints out the item, it's usefulness to the user and cost */
		count = count + 1; /* adds item count by 1 */
		sum = sum + element->costOfItem; /* adds total cost by itself + the new cost */
		element=element->next; /* move to the next item */
	}
	printf("\n\nYou bought %i items for college and your total cost is $%.2lf.\n", count, sum);
}

void main(void)
{
	char nameOfItem[50] = ""; /* stores the name of the item */ 
	int rank; /* stores the user's usefulness value of the item */
	double cost; /* stores the cost of the item */
	
	printf("This program take different college items, their usefulness and cost and outputs them as a list.\n\n");
	head = NULL; /* sets head to NULL */
	getName(nameOfItem); /* asks the user for the item name */
	while (strcmp(nameOfItem, "done") != 0 && strcmp(nameOfItem, "Done") != 0 && strcmp(nameOfItem, "DONE") != 0) /* itemName is not Done or DONE or done */
	{
		rank = getInt(); /* grab the user's usefulness value of the item */
		cost = getDouble(); /* grabs the cost the user spent on the item */
		add_element(nameOfItem, rank, cost); /* adds the name, usefulness value, and cost to the structure */
		gets(nameOfItem); /* recieves the newline after reading the double input */
		getName(nameOfItem); /* asks the user for another item name */
	}
	print_list(); /* prints the list of items the user bought to the console */
}
 