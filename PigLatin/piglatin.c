#include <stdio.h>
#include <string.h>

void main (void)
{
	char sentence[81]; /* holds input string */
	char *psentence; /* points to each word */
	
	printf("This program translates words in sentences to Pig Latin.\n");
	printf("Type stop to end the program.\n\n");
	while (sentence != "stop")
	{
		printf("Please type a sentence: ");
		scanf("%s", &sentence);
	}
	
}
