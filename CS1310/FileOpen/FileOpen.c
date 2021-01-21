
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *in, *out; /* access to in.txt */
	char astring[81];
	int num = 0;
	
	printf("This program reads from in.txt and writes to out.txt.\n\n");
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "r");
	
	fgets(astring, 80, in);
	printf("The text from in.txt is %s. \n", astring);
	fprintf(out, "The content from in.txt is \n%s. \n\n", astring);
	
	num = atoi(astring);
	printf("The string %s as an integer is %i. \n\n", astring, num);
	
	fclose(in);
	fclose(out);
}
