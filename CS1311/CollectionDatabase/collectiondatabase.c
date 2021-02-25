/* C program by Azariel Del Carmen for CS1311 Mar 2021 (Futurfying the Date)
 * This program take different college items, their usefulness
 * and cost and outputs them as a list
 */
 
#include <stdio.h>
#include <string.h>

char getName(void)
{
	char nameTemp[50];
	printf("Please type the name of the item. (Type \"done\" to stop): ");
	gets(nameTemp);
	printf("You typed %s.", nameTemp);
	return nameTemp;
}

int getInt (void)
{
	int tempInt = -1; /* get into loop to start getting a val */
	
	while(tempInt < 0) /* while temp is less than 0 */
	{ 
		printf("\nPlease type the usefulness of the item from 1-10: "); /* ask the user for a positive integer */
		scanf("%d", &tempInt);
	}
	printf("\nYou typed in %i.\n", tempInt);
	return tempInt;
}

void main(void)
{
	/* list of college dorm items, cost and usefulness */
	struct collegeDormItems
	{
		char objectName[50]; /* name of the item */
		int usefulness; /* usefulness of the item */
		double costOfItem; /* cost of the item */
		struct collegeDormItems *next; /* link the list */
	};
	struct collegeDormItems *head, *element, *last;
	char nameOfItem[50]; /* stores the name of the item for the structure */ 
	int rank;
	double cost;
	
	printf("This program take different college items, their usefulness and cost and outputs them as a list.\n\n");
	head = NULL;
	printf("Please type the name of the item. (Type \"done\" to stop): ");
	gets(nameOfItem);
	printf("You typed %s.\n", nameOfItem);
	while (strcmp(nameOfItem, "done\0\0") != 0)
	{
		printf("Pass.\n\n");
		//rank = getInt();
		//add_element(nameOfItem)
		printf("Please type the name of the item. (Type \"done\" to stop): ");
		gets(nameOfItem);
		printf("You typed %s.\n", nameOfItem);
	}
}
 