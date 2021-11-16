//---------------------------------------------------------
// Azariel Del Carmen
// Problem #40
// Problem40.c
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PERMUTATIONS.h" 

bool IsSolution(const int P[]);
void DisplaySolution(const int P[]);

//---------------------------------------------------------
int main()
//---------------------------------------------------------
{
	
    PERMUTATIONS object;
    int countPermutations, countSolutions;

    ConstructPermutations(&object, 10, USE_LEXICOGRAPHIC_PERMUTE); // or USE_JOHNSON_TROTTER (your choice)
    FindFirstPermutation(&object);
    countPermutations = countSolutions = 0;

    do
    {
        countPermutations++;

        int P[10 + 1];

        for (int i = 1; i <= 10; i++)
        {
            P[i] = GetPermutationsElement(&object, i) - 1;
        }
        if (IsSolution(P))
        {
            countSolutions++;
        }
        FindNextPermutation(&object);

    } while (!AtEndOfPermutations(&object));

        printf("%10d permutations checked, %10d solutions found (%9.5f%%)\n",
            countPermutations, countSolutions,
            100 * ((double)countSolutions / countPermutations));
    DestructPermutations(&object);

    system("PAUSE");
    return(0);
}

//---------------------------------------------------------
bool IsSolution(const int P[])
//---------------------------------------------------------
{
    int carryIn1 = 0, carryOut1 = 0, carryIn2 = 0, carryOut2 = 0, carryIn3 = 0, carryOut3 = 0, carryIn4 = 0, carryOut4 = 0, carryIn5 = 0;

    int R1 = P[7] * 1000 + 5 * 100 + P[3] * 10 + P[1] * 1;
    int R2 = P[8] * 1000 + P[6] * 100 + P[4] * 10 + 5 * 1;
    int R3 = P[10] * 10000 + P[9] * 1000 + 6 * 100 + P[5] * 10 + P[2] * 1;

    if (R1 + R2 == R3)
    {
        DisplaySolution(P);
        return true;
    }
    else
    {
        return false;
    }
}

//---------------------------------------------------------
void DisplaySolution(const int P[])
//---------------------------------------------------------
{
    printf("%d%d%d%d", P[7], 5, P[3], P[1]);
    printf(" + %d%d%d%d", P[8], P[6], P[4], 5);
    printf(" = ");
    printf("%d%d%d%d%d\n", P[10], P[9], 6, P[5], P[2]);
}
