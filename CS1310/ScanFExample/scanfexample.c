/* C program by Azariel Del Carmen for CS1310 Aug 2020
 * scanf example - get input and print it out
 */

#include <stdio.h>

void main(void){
    char letter; /* hold user's character input */
    int number; /* holds user's integer input */

    printf("This program prints out a letter that you type.\n");

    printf("Please type in a character and enter: ");
    scanf("%c", &letter);
    printf("You entered %c. \n", letter);
    scanf("%c", &letter); /* read in newline/enter character */

    printf("Please type in another character and enter: ");
    scanf("%c", &letter);
    printf("You entered %c. \n", letter);

    scanf("%c", &letter);
    printf("Please type in an integer and enter: ");
    scanf("%d", &number);
    printf("You entered %i. \n", number);
}
