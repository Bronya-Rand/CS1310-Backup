/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * check input > 0
 */
#include <stdio.h>

void main(void){
    double number = 0; /* get value from the user */

    printf("Check for a valid length.\n\n");
    printf("Input a distance or length: ");
    scanf("%lf", &number);
    printf("You typed %lf. \n", number);

    if(number <= 0){
        printf("%lf must be positive. Run the program again.\n", number);
    }else{
        printf("%lf is a good value for a length.\n", number);
        printf("You can divide by %lf such as 1/%lf = %lf. \n\n", number, number, 1.0/number);
    }
}