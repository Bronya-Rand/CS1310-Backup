/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * Tell the user if their integer number is one digit or not
 */
#include <stdio.h>

void main(void){
    int digit = 0; /* sets the digit variable */

    printf("This program tells if a given integer is one digit.\n\n");
    printf("Please provide a integer: ");
    scanf("%d", &digit);
    printf("You entered %d as your integer. \n", digit);

    /* checks given digit and sees if its 1 digit in size */
    if(digit <= 9 && digit >= -9){ /* -10 < number < 10 */
        printf("%d is a one digit integer. \n", digit);
    }else if(digit <= 99 && digit >= -99){ /* -100 < number < 100 */
        printf("%d is a two digit integer. \n", digit);
    }else if(digit <= 999 && digit >= -999){ /* -1000 < number < 1000 */
        printf("%d is a three digit integer. \n", digit);
    }else if(digit <= 9999 && digit >= -9999){ /* -10000 < number < 10000 */
        printf("%d is a four digit integer. \n", digit);
    }else if(digit <= 99999 && digit >= -99999){ /* -100000 < number < 100000 */
        printf("%d is a five digit integer. \n", digit);
    }else if(digit <= 999999 && digit >= -999999){ /* -100000 < number < 1000000 */
        printf("%d is a six digit integer. \n", digit);
    }else if(digit <= 9999999 && digit >= -9999999){ /* -1000000 < number < 10000000 */
        printf("%d is a seven digit integer. \n", digit);
    }else if(digit <= 99999999 && digit >= -99999999){ /* -10000000 < number < 100000000 */
        printf("%d is a eight digit integer. \n", digit);
    }else if(digit <= 999999999 && digit >= -99999999){ /* -10000000 < number < 100000000 */
        printf("%d is a nine digit integer. \n", digit);
    }else if(digit <= 9999999999 && digit >= -9999999999){ /* -10000000 < number < 100000000 */
        printf("%d is a ten digit integer. \n", digit);
    }else if(digit <= 99999999999 && digit >= -99999999999){ /* -10000000 < number < 100000000 */
        printf("%d is a eleven digit integer. \n", digit);
    }else{
        printf("%d is a integer greater than ten digits. \n", digit);
    }
}

//printf("%d is a integer greater than two digits. \n", digit);