/* C program by Azariel Del Carmen for CS1310 Sep 2020
 * This program asks the user for two numbers and have functions
 * for addition, subtraction, multiplication, division or all 4
 * 
 * ||||||||||||||||||||||||\_|||__|||||||||
 * |||||||||||||||||||S\_\@\_||___|||||||||
 * |||||||||||||||||SS@S\\SS__\__||||||||||
 * ||||||||||||||||S@@@@\_\S_\S_|||||||||||
 * ||||||||||||||\S@@SSSSSSSSSSSS\|||||||||
 * |||||||||||||\S@SSSSSSSSSS@S@@@SS|||||||
 * |||||||||||||S@SS@@@@@@@@@@@SSS@@S||||||
 * ||||||||||||SSSS@@@@@@@@@@@SSSSS@S\|||||
 * |||||||||||SSSSS@@@@@@@@@@SSSSSSSS\|||||
 * |||||||||||SSS@@@@@@@@@@@SSSSSSSS@S|||||
 * ||||||||||SSS@@@@@@@@@@@SSS@SSS@@@S\||||
 * ||||||||||SS@@@@@@@@@@SSSS@@\S@@@@@S_|||
 * |||||||||SS@@@@@@@@@@SSS@@@SSS@@@@SS\|||
 * ||||||||_S@@@@@@@@@SSSS@@S\\S@@@@SSS\|||
 * ||||||||SS@@@@@@SSSSS@@SS\\S@@@@@S\S\_||
 * |||||||SSS@SSSSSSSSSSS\\\SSS@@@@@S\@S_||
 * ||||||S@SSSS\SSSSS\\\\\S@@SS@@@@@S\@S_||
 * |||||S@@S\\\\\\\\\\SSSS@@@@S@@@@SS\S\|||
 * ||||S@@@S\__\___SS@@@@SSSSSSS@@@S\\S\|||
 * ||||S@@@S\\S\_\S@@@@@@SSSS@SS@@@S\\S\|||
 * |||\S@@SSSSSSSS@@@@@@@\||_\SSS@S\\\S\|||
 * |||\SSS\SSSSSS@@@@@@@@\__\__SSSS\\SS_|||
 * |||_SS\\SSSSSSSS@S@@@@S\\\@_\SS\\\S\||||
 * |||\S@@SSSSSSSSSSSSSSSSSSSSS@\\\\\S\||||
 * ||S@@@@SSS@SSS@SS@SSSSSSSSS@S\\\\\\_||||
 * |S@@@@@S\\@@@@@SS@@SSSSSSS@S\\\\\\_|||||
 * |S@@@@S@\\S@@@@@@@@@@SSSSSS\\\SSS\||||||
 * \S@@@SSS_\S@@@S@@@@@@@@SSS\\\SSS\_||||||
 * S@@@SSSS_S@S@@@SS@@@@@@S\\\SSSS\||||||||
 * S@SSSSS@S@@SS@@@@@@@@@S\\\\\\\\_||||||||
 * SSSSSSS@@@@@SS@@@@@SS\\__\\\\\_|||||||||
 * @@@@@SS@@@@@@SSSSS\\\__||_\_||||||||||||
 * @@@SSSSS@@@@@S\\\\\\__|||||||||||||||||| 
 */

/* Did you catch that this ASCII is a image illusion of a character? :p */
#include <stdio.h> /* adds standard i/o library */

double value(void)
{
    double a = 0; /* initializes a with 0 as a temporary variable */
    /* asks the user for a input */
    printf("Please type in a value: "); 
    scanf("%lf", &a);
     /* returns the user their value */
    printf("You entered %lf.\n", a);
    return a;
}

void add(double valA, double valB)
{
    /* initializes total with 0 as a temporary variable */
    double total = 0; 
    /* addition */
    total = valA + valB;
    printf("\n%lf plus %lf is equal to %lf.\n", valA, valB, total); /* returns the result to the user */
}

void sub(double valA, double valB)
{
    double total = 0;
    total = valA - valB;
    printf("\n%lf minus %lf is equal to %lf.\n", valA, valB, total);
}

void mul(double valA, double valB)
{
    double total = 0;
    total = valA * valB;
    printf("\n%lf times %lf is equal to %lf.\n", valA, valB, total);
}

void div(double valA, double valB)
{
    if (valB == 0)
    {
        printf("\nYou cannot divide a number by 0.\n");
    }
    else
    {
        double total = 0;
        total = valA / valB;
        printf("\n%lf divided by %lf is equal to %lf.\n", valA, valB, total);
    }
}

void main(void)
{
    int option = 0;
    double valA, valB = 0;
    double total;
    printf("\nThis program takes 2 numbers and does number of operations to them.\n\n");
    valA = value();
    valB = value();
    printf("==========================================================\n");
    printf("||                      Operations                      ||\n");
    printf("||    ^   ^   ^             1. Addition                 ||\n");
    printf("||     \\  |  /              2. Subtraction              ||\n");
    printf("||      \\/=\\/               3. Multiplication           ||\n");
    printf("||      /\\=/\\               4. Division                 ||\n");
    printf("||     /  |  \\              5. All Operations           ||\n");
    printf("||    V   V   V             6. Quit                     ||\n");
    printf("||                                                      ||\n");
    printf("==========================================================\n");
    printf("\nPlease select a option. ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        add(valA, valB);
        break;
    
    case 2:
        sub(valA, valB);
        sub(valB, valA);
        break;

    case 3:
        mul(valA, valB);
        break;

    case 4:
        div(valA, valB);
        div(valB, valA);
        break;
    
    case 5:
        add(valA, valB);
        sub(valA, valB);
        sub(valB, valA);
        mul(valA, valB);
        div(valA, valB);
        div(valB, valA);
        break;

    case 6:
        printf("\n\nWeiss Schnee Best Girl!\n");
        break;

    default:
        printf("\nInvalid input. Exiting.\n");
        break;
    }
}
