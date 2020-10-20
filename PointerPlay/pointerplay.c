#include <stdio.h>

void main (void)
{
	char letter='a', *pletter; /* uses character and a pointer to it */
	int num=10, *point;
	
	printf("Playing with pointers -- \n\n");
	pletter = &letter;
	printf("letter=%c &letter=%p pletter=%p *pletter=%c \n\n",
			letter, &letter, pletter, *pletter);
	*pletter = 'Z';
	printf("letter = %c \n\n", letter);
	
	printf("num=%i point=%p &num=%p \n", num, point, &num);
	point = &num;
	printf("num=%i point=%p &num=%p \n", num, point, &num);
	*point = -32;
	printf("num=%i point=%p &num=%p \n", num, point, &num);
}
