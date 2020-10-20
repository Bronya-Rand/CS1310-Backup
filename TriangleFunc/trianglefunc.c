/* C program - right triangle ... */

#include <stdio.h>
#include <math.h>

double get_leg(void)
{
    double leg;

    printf("What is the length of a leg? ");
    scanf("%lf", &leg);
    printf("You typed %lf for a leg. \n", leg);
    return leg;
}

void main(void)
{
    double a, b, c, A, B, C = 90;
    printf("Give two leg lengths and the rest of the right triangle is calculated. \n");

    a = get_leg();
    b = get_leg();
    c = sqrt( a*a + b*b );
    A = (180/3.14) * asin(a/c);
    B = (180/3.14) * asin(b/c);

    printf("The triangle has side lengths %lf, %lf, %lf and angles %lf, %lf 90. \n", a,b,c,A,B);
}