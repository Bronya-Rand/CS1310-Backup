//--------------------------------------------------
// Azariel Del Carmen
// Problem #5
// Problem5.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include "Random.h"

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void BuildRandomArray(int A[],const int n);
   void CopyArray(int copyA[],const int A[],const int n);
   void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R);
   int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS));
   void DoBubbleSort(int A[],const int n,
                     bool (*ShouldSwap)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves);
   void DoSelectionSort(int *A,const int n,
                        bool (*ShouldSelect)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   void DoInsertionSort(int *A,const int n,
                        bool (*ShouldInsert)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   bool Ascending(const int LHS,const int RHS);
   bool Descending(const int LHS,const int RHS);

   int n;

   SetRandomSeed();
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      int *A     = (int *) malloc(sizeof(int)*n);
      int copyA[n];
      int numberCompares;
      int numberMoves;

      BuildRandomArray(A,n);
      DisplayArraySlice("Unsorted",A,n,0,n-1);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(A,n,Ascending));
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(A,n,Descending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      free(A);
      printf("\nn? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------
void BuildRandomArray(int A[],const int n)
//--------------------------------------------------
{
   int i;

   for (i = 0; i <= n-1; i++)
      A[i] = RandomInt(1,10*n);
}

//--------------------------------------------------
void CopyArray(int copyA[],const int A[],const int n)
//--------------------------------------------------
{
	int i;

	i = 0;
TOL1:
	if ( !(i <= n-1) ) goto BOL1;
	copyA[i] = A[i];
	i++;
	goto TOL1;
BOL1:
	;
}

//--------------------------------------------------
void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R)
//--------------------------------------------------
{
    if (strcmp(label, "Unsorted") == 0)
    {
        printf("\nUnsorted\n");
        printf("========\n");
    }
    else if (strcmp(label, "Bubble Sort (Ascending)") == 0)
    {
        printf("\nBubble Sort (Ascending)\n");
        printf("=======================");
    }
    else if (strcmp(label, "Bubble Sort (Descending)") == 0)
    {
        printf("\nBubble Sort (Descending)\n");
        printf("========================");
    }
    else if (strcmp(label, "Selection Sort (Ascending)") == 0)
    {
        printf("\nSelection Sort (Ascending)\n");
        printf("==========================");
    }
    else if (strcmp(label, "Selection Sort (Descending)") == 0)
    {
        printf("\nSelection Sort (Descending)\n");
        printf("===========================");
    }
    else if (strcmp(label, "Insertion Sort (Ascending)") == 0)
    {
        printf("\nInsertion Sort (Ascending)\n");
        printf("==========================");
    }
    else if (strcmp(label, "Insertion Sort (Descending)") == 0)
    {
        printf("\nInsertion Sort (Descending)\n");
        printf("===========================");
    }
}

//--------------------------------------------------
int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS))
//--------------------------------------------------
{
   int i,r,j;

   for (i = 0,r = 0; i <= n-2; i++)
      for (j = i+1; j <= n-1; j++)
         if ( AreInverted(A[i],A[j]) ) r++;
   return( r );
}

//--------------------------------------------------
bool Ascending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( (LHS > RHS) ? true : false );
}

//--------------------------------------------------
bool Descending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( LHS < RHS );
}

//--------------------------------------------------
void DoBubbleSort(int A[],const int n,
                  bool (*ShouldSwap)(const int LHS,const int RHS),
                  int *numberCompares,
                  int *numberMoves)
//--------------------------------------------------
{
   int pass;
   bool swapMade;
   int i;
   
   pass = 1;
   *numberCompares = 0;
   *numberMoves = 0;
   
	DOW1:
		swapMade = false;
		i=0;
	    FOR1:
		    if(!(i<=n-(pass+1))) goto FOR1Q;
		    *numberCompares += 1;
		    IF1:
			    if ( !(ShouldSwap(*(A+i),*(A+i+1))) ) goto IF1Q;
			    int T = *(A+i); *(A+i) = *(A+i+1); *(A+i+1) = T;
		        *numberMoves += 3;
		        swapMade = true;
		    IF1Q:
		        i++;
		    goto FOR1;
	    FOR1Q:
	        pass++;
	    if(swapMade) goto DOW1;
}

//--------------------------------------------------
void DoSelectionSort(int *A,const int n,
                     bool (*ShouldSelect)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{
   *numberCompares = 0;
   *numberMoves = 0;
   
    int i = 0;
   	FOR2:
   		if(!(i <= n-2)) goto FOR2Q;
   		int T, select = i, j=i+1;
		FOR3:
			if(!(j <= n-1)) goto FOR3Q;
			IF2:
				if ( !((*ShouldSelect)(A[select],A[j]) )) goto IF2Q;
				select = j;
	         	*numberCompares += 1;
         	IF2Q:
         	    j++;
			goto FOR3;
		FOR3Q:
		    T = A[i]; A[i] = A[select]; A[select] = T;
		    ++*numberMoves, *numberMoves += 1, (*numberMoves)++;
		    i++;
		goto FOR2;
	FOR2Q:
		;
}

//--------------------------------------------------
void DoInsertionSort(int A[1],const int n,
                     bool (*ShouldInsert)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{
	int i=0;

    *numberCompares = 0;
    *numberMoves = 0;
   
   	FOR4:
   		if((i > n-1)) goto FOR4Q;
   		int v = A[i];
      	int j = i-1;
      
      	*numberMoves += 1;
      	WHL1:
	      	if(!( (j >= 0) && (*ShouldInsert)(A[j],v) )) goto WHL1Q;
	        *numberCompares += 1;
	        A[j+1] = A[j];
	        *numberMoves += 1;
	        j--;
	        goto WHL1;
      	WHL1Q:
      	    *numberCompares += 1;
      	    A[j+1] = v;
      	    *numberMoves += 1;
   	  	    i++;
   		goto FOR4;
   	FOR4Q:
   		;
}
