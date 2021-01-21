/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * This program finds prime numbers
 */

#include <stdio.h>


void main(void)
{
    int number, i=1, j, isprime = 0; /* user input; for loops; flag for number is prime */

    printf("This program prints out primes up to the number you type. \n");
    printf("Please enter a positive integer: "); /*** check >1 with do-while ***/
    scanf("%d", &number);
    printf("The number you entered is %i", number);

    printf("\nThe primes less than or equal to %i are\n", number);
    while (i < number) /* for each integer 2 to number, check if prime */
    {
        i = i + 1;
        isprime = 1; /* assume i is prime */

        for(j=2; j<i; j++) /* see if any number less than i divides into i */
        {
            if (i%j == 0) /* j divided into i; no remainder means not prime */
            {
                isprime = 0;
            }
        }
        if (isprime == 1) /* i is prime */
        {
            printf(" %i", i);
        }
    }
    
}
