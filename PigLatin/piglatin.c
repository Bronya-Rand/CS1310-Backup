#include <stdio.h>
#include <string.h>

char translate(char *sentence)
{
	int j, pos;
	char *psentence; /* points to each word */
	psentence = strtok(sentence, " "); /* gets word */
	while(psentence != NULL)
	{
		for(j=0; j < strlen(psentence); j++)
		{
			if(psentence[j] == 'a' || psentence[j] == 'e' || psentence[j] == 'i' || psentence[j] == 'o' || psentence[j] == 'u' || psentence[j] == 'A' 
			|| psentence[j] == 'E' || psentence[j] == 'I' || psentence[j] == 'O' || psentence[j] == 'U')
			{
				pos = j;
				break;
			}
		}
		if(pos == 0)
		{
			printf("%sway ", psentence);
		}
		else
		{
			for(j=pos; j < strlen(psentence); j++)
			{
				printf("%c", psentence[j]);
			}
			for(j=0; j < pos; j++)
			{
				printf("%c", psentence[j]);
			}
			printf("ay ");
		}
		//printf("   word=%s \n", psentence);
		psentence = strtok(NULL, " ");
	}
}

void main (void)
{
	char sentence[81]; /* holds input string */
	
	printf("This program translates words in sentences to Pig Latin.\n");
	printf("Type stop to end the program.\n");
	do
	{
		printf("\nPlease type a sentence: ");
		gets(sentence);
		printf("You typed \"%s\".\n\n", sentence);
		translate(sentence);
	}while(strcmp(sentence, "stop") != 0);
}
