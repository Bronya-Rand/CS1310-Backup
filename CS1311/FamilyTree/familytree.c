/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * creating a family tree; similar network program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char name[80];
	struct person *childwith;
	struct person *kid1;
	struct person *kid2;
	/* max number of kids in tree */	
};

struct person *root;
struct person me, mom, dad, grandma, grandpa, son1;

void print_node(struct person someone)
{
	printf("The person name is %s.\n", someone.name);
	if (someone.childwith != NULL)
	{
		printf(" and has a child with %s.\n", someone.childwith->name);
	}
	if (someone.kid1 != NULL)
	{
		printf(" One kid is named %s.\n", someone.kid1->name);
	}
	if (someone.kid2 != NULL)
	{
		printf(" One kid is named %s.\n", someone.kid2->name);
	}
	printf("\n");
}

void main (void)
{
	printf("This program creates and prints a family tree.\n\n");
	
	/* make family tree */
	root = &grandma;
	strcpy(grandma.name, "Unknown Grandma");
	grandma.childwith = &grandpa;
	grandma.kid1 = &mom;
	grandma.kid2 = NULL;
	
	root = &grandpa;
	strcpy(grandpa.name, "Unknown Grandpa");
	grandpa.childwith = NULL;
	grandpa.kid1 = NULL;
	grandpa.kid2 = NULL;
	
	root = &mom;
	strcpy(mom.name, "Willow Schnee");
	mom.childwith = &dad;
	mom.kid1 = &me;
	mom.kid2 = &son1;
	
	root = &dad;
	strcpy(dad.name, "Jacques Schnee");
	dad.childwith = NULL;
	dad.kid1 = NULL;
	dad.kid2 = NULL;
	
	root = &me;
	strcpy(me.name, "Weiss Schnee");
	me.childwith = NULL;
	me.kid1 = NULL;
	me.kid2 = NULL;
	
	root = &son1;
	strcpy(son1.name, "Whitley Schnee");
	son1.childwith = NULL;
	son1.kid1 = NULL;
	son1.kid2 = NULL;
	/* print each node */
	print_node(grandpa);
	print_node(grandma);
	print_node(dad);
	print_node(mom);
	print_node(me);
	print_node(son1);
}