/* C program by Azariel Del Carmen for CS1311 Mar 2021
 * This program attempts to guess a value between 1-20 from the 
 * user's head.
 *
 * ||||||SSS\\\\\\\\SS||
 * ||||SS\\`````````\S||
 * ||SS\````````````\SS|
 * |SS\``````````````\SS
 * |S\\\\\\\\\\\``````\S
 * S\\SSSSSSSSS\SSS\```S
 * S\SSSSSSSSS\\SSSS\``\
 * \\SSS\SSS\\SS\SSS\``\
 * \\S\\\\\\\SS\\\SSS``\
 * \\S\\\`\SSSS`__\SS`\S
 * S\S\\\\SSSSS\\\\\\`\S
 * S\\\\\\SSSSSS\\\\`\S|
 * SSS\\\\S\\SSS\\\\SS||
 * |SSS\\\\\\\\\\``SS|||
 * ||||SS\_____\\``SS|||
 * |||||S`|\\`|\S\`SS|||
 * |||||S_|``_|`S\`\S|||
 * ||||S\`\SS\``S\\SS|||
 * ||SS\\\\\S\\``SSS||||
 * ||S\_|`\\\\\_`S||||||
 * ||SS\__``|_\`SS||||||
 * |||SSSS``\\`\S|||||||
 * ||||||S\`\S\\S|||||||
 * ||||||SS\SSS\S|||||||
 */
 
#include <stdio.h>
#include <stdlib.h>

struct guess7 {
    int num; /* value of the number */
    struct guess7 *less; /* holds value less than num */
    struct guess7 *more; /* holds value more than num */
    };

 struct guess7 *current;
 struct guess7 one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve,
 thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty;  /* nodes */
 
 void create_guesses (void)   /* makes the binary tree */
 {
    printf ("Creating Guess Algorithm. Please Wait...\n\n");
    one.num = 1;
    one.less = NULL; 
    one.more = NULL;
    two.num = 2;
    two.less = &one;
    two.more = NULL;        
    three.num = 3;
    three.less = &two;
    three.more = &four;
    four.num = 4;
    four.less = NULL; 
    four.more = NULL;         
    five.num = 5;
    five.less = &three;
    five.more = &seven;
    six.num = 6;
    six.less = NULL;
    six.more = NULL;             
    seven.num = 7;
    seven.less = &six;
    seven.more = &nine;
    eight.num = 8;
    eight.less = NULL;
    eight.more = NULL;
    nine.num = 9;
    nine.less = &eight;
    nine.more = NULL;
    ten.num = 10;
    ten.less = &five;
    ten.more = &fifteen;
    eleven.num = 11;
    eleven.less = NULL;
    eleven.more = NULL;
    twelve.num = 12;
    twelve.less = &eleven;
    twelve.more = NULL;
    thirteen.num = 13;
    thirteen.less = &fourteen;
    thirteen.more = &twelve;
    fourteen.num = 14;
    fourteen.less = NULL;
    fourteen.more = NULL;
    fifteen.num = 15;
    fifteen.less = &thirteen;
    fifteen.more = &eighteen;
    sixteen.num = 16;
    sixteen.less = NULL;
    sixteen.more = NULL;
    seventeen.num = 17;
    seventeen.less = &sixteen;
    seventeen.more = NULL;
    eighteen.num = 18;
    eighteen.less = &seventeen;
    eighteen.more = &twenty;
    nineteen.num = 19;
    nineteen.less = NULL;
    nineteen.more = NULL;
    twenty.num = 20;
    twenty.less = &nineteen;
    twenty.more = NULL;         
    printf ("Process Complete. Let's get to guessing!\n\n");
 }

 void main (void)
 {
	int input = 0, gotIt = 0;  /* holds user selection for menu options | determines if the program found the number */
      
	printf ("This program attempts to guess a number you thought of from 1-20.\n");
	printf ("Think of a number between 1 and 20.\n");
	
	create_guesses();  /* makes the guess tree */
   
	current = &ten; /* start current at 10 */
	
	printf("##########################################\n");
	printf("#        Guessing with Chibi Neo.        #\n");
	printf("##########################################\n");
	while (input != 3)  /* while the number is not found */  
    {
    	if (current == NULL) /* if current is no number/NULL */
    	{
    		break; /* exit the while loop */
		}
		if (current->num == 10) /*  if current is not 10 */
    	{
    		printf("\n   Chibi Neo raises a sign. :NeoSmug:\n\n"); /* give this default Neo response */
		}
		else
		{
			printf("\n  Chibi Neo raises another sign. :NeoSmug:\n\n"); /* give this Neo response instead */
		}
		printf("    -------------------------------\n");
        printf ("   |      Is your number %i?       |\n", current->num);
		printf ("   |   1. No. It's less than %i.   |\n", current->num);
		printf ("   |  2. No. It's greater than %i. |\n", current->num);
		printf ("   |        3. Yes :NeoNod:        |\n");
		printf("    -------------------------------\n");
		printf("                |    |                \n");
		printf("                |    |                \n");
		printf("                |    |                \n");
		printf("                |____|                \n\n");
		printf (" Reply back with the numbers 1, 2, or 3 (don't forget to press Enter :NeoUnamused:):  ");
		scanf ("%i", &input);         
         
        switch (input)  /* move down the tree */
        {
            case 1: /* current is less than thought value */
                current = current->less;
                break;
            case 2: /* current is more than thought value */
                current = current->more;
                break;
            case 3: /* current is the thought value */
                printf ("\n Neo found it! :NeoSmile:\n");
                gotIt = 1; /* set found int to 1 or True */
                break;
            default: /* 1, 2, 3  is not entered*/
                printf (" %i is not a valid number. :NeoUnamused: Reply back with another one. \n\n", input);                      
    	}
	}
	if (gotIt == 0) /* if number was not found */
	{
		printf("\n Neo couldn't find the number. Neo wants revenge... :NeoPout:\n");
	}
	//getchar();     
}
        