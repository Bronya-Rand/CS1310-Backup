
// Azariel Del Carmen
// Problem #37
// Problem37.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

#include "Random.h"

#define DISPLAYARRAY


int main()

{
   void BuildRandomArray(int A[],const int n);
   int NumberOfInversions(const int A[],const int n);
   int MaximumInversions(const int n);
   void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R);
   void DoComparisonCountingSort(int A[],const int n,int *numberCompares);

   int n;

   SetRandomSeed();
   printf("n? "); 
   while ( scanf("%d",&n) != EOF )
   {
      int *A = (int *) malloc(sizeof(int)*n);
      int numberCompares;

      BuildRandomArray(A,n);

#ifdef DISPLAYARRAY
      DisplayArraySlice("UNSORTED",A,n,0,n-1);
#endif

        printf("# of inversions before sort is %10d (%.1f%% of %d)\n",
    	NumberOfInversions(A,n),
        100*((double) NumberOfInversions(A,n)/MaximumInversions(n)),
        MaximumInversions(n));
        DoComparisonCountingSort(A,n,&numberCompares);
      printf("# of   compares during sort is %10d\n",numberCompares);

#ifdef DISPLAYARRAY
      DisplayArraySlice("  SORTED",A,n,0,n-1);
#endif

      printf("# of inversions  after sort is %10d\n",NumberOfInversions(A,n));

      free(A);
      printf("\nn? ");
   }
   
   system("PAUSE");
   return( 0 );
}


void BuildRandomArray(int A[],const int n)

{
   for (int i = 0; i <= n-1; i++) A[i] = RandomInt(1,10*n);
}


void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R)

{
   const int WIDTH = (int) ceil(log10(10*n));
   char formatString[4+1];

   sprintf(formatString,"%%%dc",WIDTH);

   printf("%s",label);
   if ( !(L <= R) )
      printf(" (empty)\n");
   else
   {
      for (int i = 0; i <= n-1; i++)
         if ( (L <= i) && (i <= R) )
            printf("%*d",WIDTH+1,A[i]);
         else
            printf(formatString,' ');
      printf("\n");
   }
}


int MaximumInversions(const int n)

{
	int val = 0;
	val =  n*(n-1)/2;
	return val;
}


int NumberOfInversions(const int A[],const int n)
{
    int i,r;

    int invCount = 0;
	for (i = 0; i <= n-1; i++) {
    	for (r = i + 1; r <= n-1; r++) {
    		if (A[i] > A[r]){
    			invCount++;
    		}
		}
    }
	return invCount;
}

void DoComparisonCountingSort(int A[],const int n,int *numberCompares)

{
   int *count = (int *) malloc(sizeof(int)*n);
// int *S = (int *) malloc(sizeof(int)*n);
   int S[n];
   int temp = 0;
   *numberCompares = 0;

   for (int i = 1; i <= n; i++){
   		S[i-1] = A[i-1];
   }

   for (int i = 0; i <= n-1; i++){
		for(int j = i; j <= n-1; j++) {
			if (S[j] < S[i]) {
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
				*numberCompares += 1;
			}
		}
   }
   
   for (int i = 1; i <= n; i++){
   		A[i-1] = S[i-1];
   }
   free(count);
// free(S);
}
