#include <stdio.h>
#include <string.h>

char translate(char *sentence)
{
	int i = 1;
	int j;
	char *psentence; /* points to each word */
	psentence = strtok(sentence, " ");
	while(psentence != NULL)
	{
		while(psentence[0] == 'a' || psentence[0] == 'e' || psentence[0] == 'i' || psentence[0] == 'o' || psentence[0] == 'u' || psentence[0] == 'A' || psentence[0] == 'E' || psentence[0] == 'I' || psentence[0] == 'O' || psentence[0] == 'U')
		{
			i = 0;
			break;
		}
		if(i == 0)
		{
			printf("%sway\n\n", psentence);
		}
		else
		{
			for(j=i; j < strlen(psentence); j++)
			{
				printf("%c", psentence[j]);
			}
			for(j=0; j < i; j++)
			{
				printf("%c", psentence[j]);
			}
			printf("ay\n\n");
		}
		i = 1;
		//printf("   word=%s \n", psentence);
		psentence = strtok(NULL, " ");
	}
}

void main (void)
{
	char sentence[81]; /* holds input string */
	
	printf("This program translates words in sentences to Pig Latin.\n");
	printf("Type stop to end the program.\n\n");
	do
	{
		printf("Please type a sentence: ");
		gets(sentence);
		printf("You typed \"%s\".\n\n", sentence);
		translate(sentence);
	}while(strcmp(sentence, "stop") != 0);
}
