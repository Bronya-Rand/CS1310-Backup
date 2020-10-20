/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * says which of two numbers is smaller/larger with functions
 */

#include <stdio.h>


double get_number(void) /* returns a number */
{
    double number; /* user input */

    printf("Please type in a number: ");
    scanf("%lf", &number);
    printf("You entered %lf. \n", number);
    return number;
}

/* prints the relationship between two values */
void PrintMoreOrLess (double one, double two)
{
    if (one<two)
        printf("%lf is smaller and %lf is larger. \n", one, two);
    else if (two<one)
            printf("%lf is smaller and %lf is larger. \n", two, one);
    else
        printf("%lf and %lf are equal. \n", one, two);
}

void main(void)
{
    double first, second; /* numbers input by the user */

    printf("This program tells you what number is more or less. \n");
    first = get_number();
    second = get_number();
    printf("Your values are %lf and %lf. \n\n", first, second);

    PrintMoreOrLess(first, second);
}