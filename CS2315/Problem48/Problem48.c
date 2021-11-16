//-------------------------------------------------------------
// Azariel Del Carmen
// Problem #48
// Problem48.c
//-------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

#include "Combinations.h"

//-------------------------------------------------------------
int main()
//-------------------------------------------------------------
{
    bool IsPrime(const int x);

    int LB, UB, x,k,i;

    printf("LB? ");
    while (scanf("%d", &LB) != EOF)
    {
        int n;
        int count;

        printf("UB? "); scanf("%d", &UB);
        n = (int)(sqrt(UB) + 0.5);
        count = 0;

        for (x = LB; x <= UB; x++)
        {
            bool isExpressable = false;
            bool isExpression1 = true;

            for (k = 1; k <= n; k++)
            {
                COMBINATIONS C;

                ConstructCombinations(&C, n, k);
                FindFirstCombination(&C);
                do
                {
                    int sum = 0;

                    for (i = 1; i <= n; i++)
                    {
                        if (GetCombinationsElement(&C, i))
                        {
                            sum += (i * i);
                        }
                    }
                    if (sum == x)
                    {
                        isExpressable = true;
                        printf("%3i = ", x);
                        for (i = 1; i <= n; i++)
                        {
                            if (GetCombinationsElement(&C, i))
                            {
                                printf("%i^2 ", i);
                            }
                        }
                        printf("\n");
                    }

                    FindNextCombination(&C);
                } while (!AtEndOfCombinations(&C));
                DestructCombinations(&C);
            }
            if (!isExpressable)
            {
                count++;
                printf("***%2d: %7d", count, x);
                if (IsPrime(x))
                    printf(" (prime)");
                printf("\n");
            }
        }

        printf("\nLB? ");
    }

    system("PAUSE");
    return(0);
}

//-------------------------------------------------------------
bool IsPrime(const int x)
//-------------------------------------------------------------
{
    bool r;
    
    int i;

    if (x == 1)
        r = false;
    else
    {
        r = true;
        for (i = 2; i <= (int)(sqrt(x) + 0.5); i++)
            r = r && (x % i != 0);
    }
    return(r);
}
