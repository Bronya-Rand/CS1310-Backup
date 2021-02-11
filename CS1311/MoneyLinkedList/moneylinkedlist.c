

#include <stdio.h>
#include <string.h>

struct node 
{
	char money[40]; /* name of coin type */
	int value; /* number of cents */
	struct node *next; /* link to nodes */
};
struct node m1, m2, m3, m4, m5, m6; /* nodes names */
struct node *item; /* walk through the list */

void main (void)
{
	printf("This program shows a linked list of coins. \n");
	
	strcpy(m1.money, "quarter");
	m1.value = 25;
	m1.next = &m2;
	strcpy(m2.money, "dime");
	m2.value = 10;
	m2.next = &m3;
	strcpy(m3.money, "penny");
	m3.value = 1;
	m3.next = NULL;
	
	printf("&m1=%p m1.next=%p A %s is worth %i cents. \n", &m1, m1.next, m1.money, m1.value);
	printf("\n\n");
	
	/* print nodes by a loop */
	item = &m1;
	while (item != NULL)
	{
		printf("item=%p  money=%s  value=%i  \n", item, item -> money, item -> value);
		item = item -> next; /* get to next element */
	}
}
