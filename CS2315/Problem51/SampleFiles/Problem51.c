//-------------------------------------------------------------
// Azariel Del Carmen
// Problem #51
// Problem51.c
//-------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Random.h"

//-------------------------------------------------------------
int main()
//-------------------------------------------------------------
{
/*
             minimum               maximum        average                    n!
--------------------  --------------------  -------------  --------------------
XXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXX  XXXXXXXXXX.XX  XXXXXXXXXXXXXXXXXXXX
*/

   void RunOneTrial(unsigned long long int *count,const int n,
                    bool (*EQ)(const int xs1[],const int xs2[],const int n));
   bool AreEQ(const int xs1[],const int xs2[],const int n);
   signed long long int Factorial(const int n);

   int T,n;

   SetRandomSeed();

   printf("T n? ");
   while ( scanf("%d%d",&T,&n) != EOF )
   {
      int i;
      unsigned long long count,minCount,maxCount,sumCount;

      RunOneTrial(&count,n,AreEQ);
      minCount = count;
      maxCount = count;
      sumCount = count;
      for (i = 2; i <= T; i++)
      {
         RunOneTrial(&count,n,AreEQ);
         if ( count < minCount ) minCount = count;
         if ( count > maxCount ) maxCount = count;
         sumCount += count;
      }
      printf("             minimum               maximum        average                    n!\n");
      printf("--------------------  --------------------  -------------  --------------------\n");
      printf("%20llu  %20llu  %13.2f  %20lld\n",minCount,maxCount,(double) sumCount/T,Factorial(n));

      printf("\nT n? ");
   }

   system("PAUSE");
   return( 0 );
}

//-------------------------------------------------------------
bool AreEQ(const int xs1[],const int xs2[],const int n)
//-------------------------------------------------------------
{
	int i;
	bool status = true;
	
	for (i = 1; i <= n; i++){
		if (xs1[i] != xs2[i]){
			status = false;
		}
	}
	return status;
}

//-------------------------------------------------------------
long long int Factorial(const int n)
//-------------------------------------------------------------
{
	int total = 1;
	int m;
	for(m = 1; m <= n; m++){
		total = total * m;
	}
	return total;
}

//-------------------------------------------------------------
void RunOneTrial(unsigned long long int *count,const int n,
                 bool (*EQ)(const int xs1[],const int xs2[],const int n))
//-------------------------------------------------------------
{
   void RandomlyFillWithoutReplacement(int xs[],const int n);

   int *xs1 = (int *) malloc(sizeof(int)*(n+1));
   int *xs2;
   
   xs2 = (int *) malloc(sizeof(int)*(n+1));
   *count = 0;
   do
   {
      RandomlyFillWithoutReplacement(xs1,n);
      RandomlyFillWithoutReplacement(xs2,n);
      (*count)++;
   } while ( !EQ(xs1,xs2,n) );

   free(xs1);
   free(xs2);
}

//-------------------------------------------------------------
void RandomlyFillWithoutReplacement(int xs[],const int n)
//-------------------------------------------------------------
{
   bool XInXs(const int xs[],const int n,const int x);
   
   int i;

   for(i = 1; i <= n; i++)
   {
      int x;

      do
      {
         x = RandomInt(1,n);
      } while ( XInXs(xs,i-1,x) );
      
      xs[i] = x;
   }
}

//-------------------------------------------------------------
bool XInXs(const int xs[],const int n,const int x)
//-------------------------------------------------------------
{
   int i;
   
   for(i = 1; i <= n; i++){
		if(xs[i] == x){
			return true;
		}
   }
   return false;
}
