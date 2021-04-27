/*
 *
 */
 
#include <stdio.h>

int stack[1000]; /* stack of integers */
int data, top=1; /* item for stack; top of stack */

void main(void)
{
	int option, reply; /* menu selection */
	
	printf("This program emulates a stack of integers.\n");
	do
	{
		printf("\n\n\nSelect an operation on the stack.\n");
		printf("   1. Push - put on stack \n");
		printf("   2. Pop - take off stack \n");
		printf("   3. Print the stack \n"); 
		/** add Peek **/
		printf("   4. Quit\n");
		printf("Type 1, 2,3 or 4 and Enter: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				printf("\nWhat integer value?: ");
				scanf("%d", &data);
				printf("will push %i to stack\n", data);
				break;
			case 2:
				printf("will pop off last item \n");
				break;
			case 3:
				printf("print stack\n");
				break;
			case 4:
				printf("Thanks for using this stack. \n\n");
				break;
			default:
				printf("\n %i is not a valid option. Try again.", option);
		}
		
	} while (option != 4);
}