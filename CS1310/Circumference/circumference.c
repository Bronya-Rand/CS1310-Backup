/* C program by Azariel Del Carmen for CS1310 Aug 2020
 * find the circumference of a circle given a user's radius
 */

#include <stdio.h>
#define pi 3.1416

void main(void){
    double radius, circumference; /* radius and C in cm for circle */

    printf("This program finds the circumference of a circle with your radius. \n");
    printf("Type in the radius in cm: ");
    scanf("%lf", &radius);
    printf("You entered %.4lf cm. \n\n", radius);

    circumference = 2 * pi * radius; /* C = 2 pi r */
    printf("Your circle with radius %.4lf cm has a circumference of %.4lf cm. \n\n\n",
            radius, circumference);
    /* calculate area A = pi r^2 */
    printf("And the area is %.4lf sq cm. \n\n\n",
           pi * radius * radius);
}