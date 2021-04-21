/* C program by Azariel Del Carmen for CS1311 Apr 2021
 * This program presents the connections of a university ID 
 * on-campus as a network.
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

struct helpDesk {
	char *name; /* name of item */
	char *type; /* item type */
	struct helpDesk *connectedTo1; /* 1st connection */
	struct helpDesk *connectedTo2; /* 2nd connection */
	struct helpDesk *connectedTo3; /* 3rd connection */
	struct helpDesk *execute; /* does this task */
};

struct helpDesk human, camera, computer, printer, iD, workStudyHuman, *root;

enum debug{off,on}; /* sets debug mode to on or off */
enum debug debugSetting; /* controls on/off for debug mode */

/* adds a network item to the structure network */
void addItems(struct helpDesk *item, char *itemName, char *kind, struct helpDesk *related1, struct helpDesk *related2, struct helpDesk *related3, struct helpDesk *doIt)
{
	if (debugSetting == 1) /* debug mode is on */
	{
		printf("Item %s is being added at location %i.\n", itemName, item);
	}
	/* sets the network item's characteristics */
	item->name = itemName; 
	item->type = kind; 
	item->connectedTo1 = related1; 
	item->connectedTo2 = related2; 
	item->connectedTo3 = related3; 
	item->execute = doIt;
	if (debugSetting == 1) 
	{
		printf("Item %s has been added.\n", itemName, item);
	}
}

/* creates items w/ characteristics */
void createItems(void)
{
	if (debugSetting == 1) /* debug mode is on */
	{
		printf("\nCreating the items to make a ID on-campus.\n\n");
	}
	
	/* adds network items to network structure */
	addItems(&human, "Person", "Student/Staff", &camera, NULL, NULL, NULL); 
	addItems(&camera, "Camera", "Nikon", &human, &computer, NULL, NULL); 
	addItems(&computer, "Computer", "Dell", &camera, &workStudyHuman, NULL, NULL); 
	addItems(&workStudyHuman, "John", "Workstudy Person", &computer, NULL, NULL, NULL); 
	addItems(&printer, "Printer", "Datacard", NULL, NULL, NULL, &computer);
	addItems(&iD, "ID Card", "Smartcard ID", NULL, NULL, NULL, &printer);
}

/* prints items/characteristics to the console */
void printItems(struct helpDesk *item)
{
	printf("\nItem: %s\n", item->name);
	if (debugSetting == 1) /* debug mode on */
	{
		printf("Location in memory %p\n", &item);
	}
	printf("Type: %s\n\n", item->type);
	printf("This item is related to:\n");
	if (item->connectedTo1 != NULL) /* has 1st connection */
	{
		printf("    %s\n", item->connectedTo1->name);
	}
	if (item->connectedTo2 != NULL) /* has 2nd connection */
	{
		printf("    %s\n", item->connectedTo2->name);
	}
	if (item->connectedTo3 != NULL) /* has 3rd connection */
	{
		printf("    %s\n", item->connectedTo3->name);
	}
	if (item->execute != NULL) /* has linked connection */
	{
		printf("This item is linked with this connection: \n    %s\n", item->execute->name);
	}
}

void main (int argc, char *argv[])
{
	printf("This program show the network connection of a university ID on-campus.\n");
	
	if (argc >= 2 && strcmp(argv[1], "debug") == 0) /* if argurments is debug */
	{
		debugSetting = on; /* set debug mode to on */
	}
	createItems(); /* creates the network */
	
	/* prints the network layout */
	printItems(&human);
	printItems(&camera);
	printItems(&computer);
	printItems(&workStudyHuman);
	printItems(&printer);
	printItems(&iD);
	
	getchar(); /* stops program from exiting */
}
