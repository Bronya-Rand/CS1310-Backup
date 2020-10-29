#include <stdio.h>
#include <string.h>

void main (void)
{
	int position = 0;
	int length,i;
	char sentence[80]; /* holds input string */
	char *psentence; /* points to each word */
	
	printf("This program translates words in sentences to Pig Latin.\n");
	printf("Type stop to end the program.\n\n");
	do
	{
		printf("Please type a sentence: ");
		gets(sentence);
		printf("You typed \"%s\".\n", sentence);
		
		psentence = strtok(sentence, " ");
		while(psentence != NULL)
		{
			printf("   word=%s \n", psentence);
			psentence = strtok(NULL, " ");
		}
	}while(strcmp(sentence, "end") != 0);
}
