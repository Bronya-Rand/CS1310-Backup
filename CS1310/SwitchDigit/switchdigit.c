/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * Use a switch case to determine and print 1 digit
 */
#include <stdio.h>

void main(void){
    int digit =0;
    printf("This program prints a digit that is 1 digit long.");
    printf("Please enter a digit: ");
    scanf("%d", &digit);
    printf("You entered %d as your number.", digit);

    switch (digit){
        case 0:
            printf("zero");
            break;
        case 1:
            printf("zero");
            break;
        case 2:
            printf("zero");
            break;
        case 3:
            printf("zero");
            break;
        case 4:
            printf("zero");
            break;
        case 5:
            printf("zero");
            break;
        case 6:
            printf("zero");
            break;
        case 7:
            printf("zero");
            break;
        case 8:
            printf("zero");
            break;
        case 9:
            printf("zero");
            break;
        default:
            printf("%d does not work.", digit);
    }
    printf(". \n\n\n")
}