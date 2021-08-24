//-------------------------------------------------------------
// Dr. Art Hanna
// Play #1 for Problem #51
// Play1.c
//-------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//-------------------------------------------------------------
int main()
//-------------------------------------------------------------
{
   int n = 10;

{ // Method #1
   printf("Method #1\n"
          "---------\n");
   int *xs = (int *) malloc(sizeof(int)*(n+1));
   printf("   &xs = %010d %08X\n",  &xs,   &xs);
   printf("    xs = %10d %08X\n",    xs,    xs);
   printf("&xs[0] = %10d %08X\n",&xs[0],&xs[0]);
   printf("\n");
   free(xs);
}

{ // Method #2
   printf("Method #2\n"
          "---------\n");
   int xs[n+1];
   printf("   &xs = %010d %08X\n",  &xs,   &xs);
   printf("    xs = %10d %08X\n",    xs,    xs);
   printf("&xs[0] = %10d %08X\n",&xs[0],&xs[0]);
   printf("\n");
}

{ // Method #3
   printf("Method #3\n"
          "---------\n");
   int *xs;
   xs = (int *) malloc(sizeof(int)*(n+1));
   printf("   &xs = %010d %08X\n",  &xs,   &xs);
   printf("    xs = %10d %08X\n",    xs,    xs);
   printf("&xs[0] = %10d %08X\n",&xs[0],&xs[0]);
   printf("\n");
   free(xs);
}
   
   system("PAUSE");
   return( 0 );
}
