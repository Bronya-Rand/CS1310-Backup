#include <stdio.h>
#include <stdlib.h>

struct guess7 {
    int num; 
    struct guess7 *less;
    struct guess7 *more;
    };

 struct guess7 *root, *current;
 struct guess7 one, two, three, four, five, six, seven;  /* nodes */
 
 void create_guess7 (void)   /* makes the binary tree */
 {
  four.num = 4;
  four.less = &two; 
  four.more = &six;
  two.num = 2;
  two.less = &one;
  two.more = &three;
  six.num = 6;
  six.less = &five;
  six.more = &seven;
  one.num = 1;
  one.less = NULL;
  one.more = NULL;     
  three.num = 3;
  three.less = NULL;
  three.more = NULL;     
  five.num = 5;
  five.less = NULL;
  five.more = NULL;     
  seven.num = 7;
  seven.less = NULL;
  seven.more = NULL;     
  printf ("Let me start to guess your number...\n");
 }

 void main (void)
 {
	int whichone = 0;  /* holds user selection from menu options */
      
	printf ("Think of a number between 1 and 7. Don't tell me yet. \n");
	create_guess7();  
   
	current = &four;
	while (whichone != 3)  /* while not quit */  
	/*** add && current != NULL */
    {
        printf ("Is your number %i? \n", current->num);
		printf ("1. My number is less than %i. \n", current->num);
		printf ("2. My number is more than %i. \n", current->num);
		printf ("3. You got my number! \n\n");
		printf ("Type in 1, 2, or 3 and enter:  ");
		scanf ("%i", &whichone);         
         
        switch (whichone)  /* move down the tree */
        {
            case 1:
                current = current->less;
                break;
            case 2:
                current = current->more;
                break;
            case 3:
                printf ("\n\nLater...\n");
                break;
            default:
                printf ("%i is not valid. Try again. \n\n", whichone);                      
    	}
	}
    //getchar();     
}
        