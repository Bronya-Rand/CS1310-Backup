//--------------------------------------------------
// Dr. Art Hanna
// Problem #24
// Problem24.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SHOWCLIMB

//#define LARGEST_STEPSIZE 2

const int LARGEST_STEPSIZE = 2;

//--------------------------------------------------
int main()
//--------------------------------------------------
{
    void ClimbNStairs(int climb[], int steps, const int n, int *ways);

    int n;

    printf("n? ");
    while (scanf("%d", &n) != EOF)
    {
        int *climb = (int *)malloc(sizeof(int) * (n + 1));
        int ways;

        for (int i = 1; i <= n; i++)
        {
            climb[i - 1] = 1;
        }

        ways = 0;
        int y = LengthOfClimb(climb, n);
        printf("%d\n", y);
        ClimbNStairs(climb,0,n,&ways);

#ifndef SHOWCLIMB
        printf("%10d ways\n", ways);
#endif

        free(climb);
        printf("n? ");
    }

    system("PAUSE");
    return (0);
}
//--------------------------------------------------
void ClimbNStairs(int climb[],int steps,const int n,int *ways)
//--------------------------------------------------
{
   int LengthOfClimb(const int climb[],const int steps);
   void ShowClimb(const int climb[],const int steps,const int ways);

   if ( LengthOfClimb(climb,steps) == n )
   {
      (*ways)++;

// #ifdef SHOWCLIMB
//       ShowClimb(climb,steps,*ways);
// #endif

    }
    else
    {
        int stepSize;

        for (stepSize = 1; stepSize <= LARGEST_STEPSIZE; stepSize++) {
            if (LengthOfClimb(climb, steps)+stepSize <= n) {
                climb[++steps] = stepSize;
                ClimbNStairs(climb, steps, n, *ways);
                steps--;
            }
        }
    
    }
}

//--------------------------------------------------
int LengthOfClimb(const int climb[], const int steps)
//--------------------------------------------------
{
    int temp = 0;
    for (int i = 1; i <= steps; i++)
    {
        temp += climb[i - 1];
    }
    return temp;
}

// //--------------------------------------------------
// void ShowClimb(const int climb[],const int steps,const int ways)
// //--------------------------------------------------
// {

//    Student provides missing code to display the climb[] using the required format

//             1         2         3
//    123456789012345678901234567890
//    WWWWW (XXX): SSS...SSS

//    where WWWWW is the value of the formal parameter ways,
//          XXX is the value of the formal parameter steps, and
//          SSS...SSS are the step-sizes of each individual step taken recorded in the formal parameter climb[]

// }
