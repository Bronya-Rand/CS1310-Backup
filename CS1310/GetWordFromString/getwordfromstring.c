/* C program by Azariel Del Carmen for CS1310 Oct 2020
 * get words from a sentence
 */
#include <string.h>
#include <stdio.h> 
 
void main (void)
{
	char words[] = "weiss schnee best girl";
	char *point; /* point to the start of each word */
	
	printf("The string is %s \nThe words are \n", words);
	point = strtok(words, " "); /* point will be the first word */
	
	while (point != NULL) /* while more words in string words */
	{
		printf("   %-16s  (word starts at %p) \n", point, point);
		point = strtok(NULL, " "); /* get next word; replaces ' ' with \0 */
	}
}
