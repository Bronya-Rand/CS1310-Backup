// Dr. Art Hanna
// Study of recursive dynamics of Problem #22 GCD4()
// StudyOfGCD4.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Global data definitions
const int TAB = 2;
char NAME[6+1] = "GCD4()";             // or, char *NAME = "GCD4()";
int depth;

int main()
{
   int GCD4(const int m,const int n);
   void ComputeGCD4(const int m,const int n,int *gcd);

   int m;

   printf("&depth    = %10d, 0X%08p\n",&depth,&depth);
   printf("&TAB      = %10d\n",&TAB);
   printf("NAME      = %10d\n",NAME);
   printf("&NAME[0]  = %10d\n",&NAME[0]);
   printf("&\"GCD4()\" = %10d\n","GCD4()");
   printf("main()    = %10d, &main() = %10d\n",main,&main);
   printf("GCD4()    = %10d\n",GCD4);

   printf("\nm? ");
   while ( scanf("%d",&m) != EOF )
   {
      int *n,gcd;
      
      n = (int *) malloc(sizeof(int));

      printf("n? "); scanf("%d",n);

      printf("\nmain() &m = %10d, &n = %10d, n = %10d, *n = %5d, &gcd = %10d\n\n",&m,&n,n,*n,&gcd);

      depth = 0;
      printf("\nGCD4(m,n) = %d\n\n",GCD4(m,*n));
      ComputeGCD4(*n,m,&gcd); printf("\nGCD4(n,m) = %d\n",gcd);

      printf("\nm? ");
   }
   
   system("PAUSE");
   return( 0 );
}

int GCD4(const int m,const int n)
{
   int r;

   if ( depth > 0 ) printf("%*c",depth*TAB,' ');
   printf("(%5d,%5d), &m = %10d, &n = %10d, &r = %10d\n",m,n,&m,&n,&r);
   depth++;

   if ( n == 0 )
      r = m;
   else
      r = GCD4(n,m%n);

   depth--;
   if ( depth > 0 ) printf("%*c",depth*TAB,' ');
   printf("(%5d,%5d)\n",m,n);

   return( r );
}

void ComputeGCD4(const int m,const int n,int *gcd)
{
   int GCD4(const int m,const int n);

   depth = 0;
   *gcd = GCD4(m,n);

   printf("\nComputeGCD4() &m = %10d, &n = %10d, &gcd = %10d, gcd = %10d, *gcd = %5d\n\n",&m,&n,&gcd,gcd,*gcd);
}
