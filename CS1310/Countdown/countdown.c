/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * simple for loop - count down!
 */
#include <stdio.h>

void main(void)
{
    int count, number = 0; /* to count down and to hold users numbers */

    printf("This program will count down from the number you give.\n");

    do
    {
        printf("Please type in a positive integer: ");
        scanf("%i", &number);
    } while (number <= 0);
    printf("You entered %i.\n\n", number);

    printf("Count down!\n");
    for(count=number; count>=0; count--)
    {
        printf(" %i ", count);
    }
    printf("\n Count down again! \n");
    for(count=0; count<=number; count++)
    {
        printf(" %i ", number-count);
    }

    printf("\n\n Count up! \n");
    for(count=1; count<=number; count++)
    {
        printf(" %i ", count);
    }

    printf("\n\n Count down! \n");
    count=number;
    while (count >= 0) /* cound down with a while */
    {
        printf(" %i ", count);
        count = count - 1;
    }
    printf("\n\n");
    
}