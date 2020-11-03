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
 
#include <stdio.h> /* standard i/o library */
#include <string.h> /* string library */

char translate(char *sentence) /* function that handles sentence and word translations */
{
	int j, pos; /* initalizes j for for loops and pos for holding letter position value */
	char *psentence; /* points to each word */
	psentence = strtok(sentence, " "); /* gets word in the sentence*/
	while(psentence != NULL) /* makes sure it runs if it's not NULL, \0, etc. */
	{
		for(j=0; j < strlen(psentence); j++) /* for loop that controls letter position of the word */
		{
			if(psentence[j] == 'a' || psentence[j] == 'e' || psentence[j] == 'i' || psentence[j] == 'o' || psentence[j] == 'u' || psentence[j] == 'A' 
			|| psentence[j] == 'E' || psentence[j] == 'I' || psentence[j] == 'O' || psentence[j] == 'U') /* checks if the letter in j position is a vowel */
			{
				pos = j; /* sets pos to j */
				break;
			}
		}
		if(pos == 0) /* if it found a vowel in position 0 */
		{
			printf("%sway ", psentence); /* prints word with way i.e Echo to Echoway */
		}
		else
		{
			for(j=pos; j < strlen(psentence); j++) /* for loop that adds the letters after position for translation */
			{
				printf("%c", psentence[j]); /* prints letter at pos and after pos to translate to ay i.e. Schnee to ee */
			}
			for(j=0; j < pos; j++) /* for loop that adds text from pos 0 to pos */
			{
				printf("%c", psentence[j]); /* prints letter at j to pos to translate i.e. Schnee to eeSchn */
			}
			printf("ay "); /* prints ay to end translation i.e. Schnee to eeSchnay */
		}
		psentence = strtok(NULL, " "); /* grabs next word of the sentence */
	}
}

void main (void)
{
	char sentence[81]; /* holds input of sentence in a char string */
	
	printf("This program translates words in sentences to Pig Latin.\n"); /* tells the user the program purpose and how to stop it */
	printf("Type stop to end the program.\n");
	do
	{
		printf("\nPlease type a sentence: ");
		gets(sentence); /* grabs the input and places it in sentence */
		printf("You typed \"%s\".\n\n", sentence); /* prints the sentence back to the user */
		translate(sentence); /* calls the translate function with the sentence */
	}while(strcmp(sentence, "stop") != 0); /* if user inputs stop, after translating stop, the program ends */
}
