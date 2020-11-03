/* C program by Azariel Del Carmen for CS1310 Oct 2020
 * This program translates a english word and sentence to pig latin.
 * 
 * ||||||||||||||||||||||||\_|||__|||||||||
 * |||||||||||||||||||S\_\@\_||___|||||||||
 * |||||||||||||||||SS@S\\SS__\__||||||||||
 * ||||||||||||||||S@@@@\_\S_\S_|||||||||||
 * ||||||||||||||\S@@SSSSSSSSSSSS\|||||||||
 * |||||||||||||\S@SSSSSSSSSS@S@@@SS|||||||
 * |||||||||||||S@SS@@@@@@@@@@@SSS@@S||||||
 * ||||||||||||SSSS@@@@@@@@@@@SSSSS@S\|||||
 * |||||||||||SSSSS@@@@@@@@@@SSSSSSSS\|||||
 * |||||||||||SSS@@@@@@@@@@@SSSSSSSS@S|||||
 * ||||||||||SSS@@@@@@@@@@@SSS@SSS@@@S\||||
 * ||||||||||SS@@@@@@@@@@SSSS@@\S@@@@@S_|||
 * |||||||||SS@@@@@@@@@@SSS@@@SSS@@@@SS\|||
 * ||||||||_S@@@@@@@@@SSSS@@S\\S@@@@SSS\|||
 * ||||||||SS@@@@@@SSSSS@@SS\\S@@@@@S\S\_||
 * |||||||SSS@SSSSSSSSSSS\\\SSS@@@@@S\@S_||
 * ||||||S@SSSS\SSSSS\\\\\S@@SS@@@@@S\@S_||
 * |||||S@@S\\\\\\\\\\SSSS@@@@S@@@@SS\S\|||
 * ||||S@@@S\__\___SS@@@@SSSSSSS@@@S\\S\|||
 * ||||S@@@S\\S\_\S@@@@@@SSSS@SS@@@S\\S\|||
 * |||\S@@SSSSSSSS@@@@@@@\||_\SSS@S\\\S\|||
 * |||\SSS\SSSSSS@@@@@@@@\__\__SSSS\\SS_|||
 * |||_SS\\SSSSSSSS@S@@@@S\\\@_\SS\\\S\||||
 * |||\S@@SSSSSSSSSSSSSSSSSSSSS@\\\\\S\||||
 * ||S@@@@SSS@SSS@SS@SSSSSSSSS@S\\\\\\_||||
 * |S@@@@@S\\@@@@@SS@@SSSSSSS@S\\\\\\_|||||
 * |S@@@@S@\\S@@@@@@@@@@SSSSSS\\\SSS\||||||
 * \S@@@SSS_\S@@@S@@@@@@@@SSS\\\SSS\_||||||
 * S@@@SSSS_S@S@@@SS@@@@@@S\\\SSSS\||||||||
 * S@SSSSS@S@@SS@@@@@@@@@S\\\\\\\\_||||||||
 * SSSSSSS@@@@@SS@@@@@SS\\__\\\\\_|||||||||
 * @@@@@SS@@@@@@SSSSS\\\__||_\_||||||||||||
 * @@@SSSSS@@@@@S\\\\\\__|||||||||||||||||| 
 */

/* include standard i/o and string libraries */
#include <stdio.h> 
#include <string.h>

/* function that handles sentence and word translations */
char translate(char *sentence) 
{
	/* initalizes j for for loops, pos for letter position and 
	isVowel checks if word is vowel which is assigned 0 i.e. not a vowel */
	int j, pos, hasVowel = 0; 
	/* points to each word */
	char *psentence; 
	
	/* gets word in the sentence*/
	psentence = strtok(sentence, " "); 
	
	/* makes sure it runs if it's not NULL, \0, etc. */
	while(psentence != NULL) 
	{
		/* for loop that controls letter position of the word */
		for(j=0; j < strlen(psentence); j++) 
		{
			if(psentence[j] == 'a' || psentence[j] == 'e' || psentence[j] == 'i' || psentence[j] == 'o' || psentence[j] == 'u' || psentence[j] == 'A' 
			|| psentence[j] == 'E' || psentence[j] == 'I' || psentence[j] == 'O' || psentence[j] == 'U') /* checks if the letter in j position is a vowel */
			{
				/* sets pos to j */
				pos = j; 
				/* sets hasVowel to 1 meaning there is a vowel */
				hasVowel = 1; 
				break;
			}
		}
		/* checks if there is a vowel in position 0 or word is not a vowel*/
		if(pos == 0 || hasVowel == 0) 
		{
			/* prints word with way i.e Echo to Echoway */
			printf("%sway ", psentence); 
		}
		else
		{
			/* for loop that adds the letters after position for translation */
			for(j=pos; j < strlen(psentence); j++) 
			{
				/* prints letter at pos and after pos to translate to ay i.e. Schnee to ee */
				printf("%c", psentence[j]); 
			}
			/* for loop that adds text from pos 0 to pos */
			for(j=0; j < pos; j++) 
			{
				/* prints letter at j to pos to translate i.e. Schnee to eeSchn */
				printf("%c", psentence[j]); 
			}
			/* prints ay to end translation i.e. Schnee to eeSchnay */
			printf("ay "); 
		}
		
		/* grabs next word of the sentence */
		psentence = strtok(NULL, " "); 
	}
}

void main (void)
{
	/* holds input of sentence in a char string */
	char sentence[81]; 
	
	/* tells the user the program purpose and how to stop it */
	printf("This program translates words in sentences to Pig Latin.\n"); 
	printf("Type stop to end the program.\n");
	do
	{
		printf("\nPlease type a sentence: ");
		/* grabs the input and places it in sentence */
		gets(sentence); 
		/* prints the sentence back to the user */
		printf("You typed \"%s\".\n\n", sentence); 
		/* calls the translate function with the sentence */
		translate(sentence); 
	/* continue until user inputs stop with no additional words */
	}while(strcmp(sentence, "stop\0\0") != 0); 
}
