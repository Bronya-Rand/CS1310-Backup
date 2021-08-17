#include <stdio.h>

int calling (int n)   /* resursive function */
{ 
    printf("n=%d; !0, add %d \n", n, 2*n+1); 
    
    if (n == 0)
    {
        return (0);
	}
	else
	{
        return (calling(n-1) + 2*n + 1); 
	}
}


void main (void)
{
	printf("\n calling(3) = %d ",  calling(3)  );
}  