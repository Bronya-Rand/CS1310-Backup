// Azariel Del Carmen
// Problem #22
// Problem22.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>
#include <math.h>

#define MAXFACTORS 512

// Commented-out in lieu of using <stdbool.h> definition of the bool data type
// typedef enum { false = 0,true = 1 } boolean;

typedef struct FACTORIZATION
{
	int size;
	int factor[MAXFACTORS+1];
	int exponent[MAXFACTORS+1];
} FACTORIZATION;

int main()
{
	int GCD1(int m,int n);
	int GCD2(const int m,const int n);
	int GCD3(const int m,const int n);
   	int GCD4(const int m,const int n);

   	int m,n;

   	printf("m? ");
   	while ( scanf("%d",&m) != EOF )
	{
    	printf("n? "); scanf("%d",&n);
      
      	assert( (m >= 0) && (n >= 0) );
      
      	printf("GCD1(m,n) = %d\n",GCD1(m,n));
      	printf("GCD2(m,n) = %d\n",GCD2(m,n));
      	printf("GCD3(m,n) = %d\n",GCD3(m,n));
      	printf("GCD4(m,n) = %d\n",GCD4(m,n));
      	printf("\nm? ");
   	}

   	system("PAUSE");
   	return( 0 );
}

int GCD1(int m,int n)
{
	int x = 0;
	int y = 0;
	
   	if (m == 0 || n == 0) {
    	return ( -1 );
    }
    
    if (m > n) {
    	x = m;
    	y = n;
	}
   	else {
   		x = n;
    	y = m;
	}
    
    while (x % y != 0) {
    	int temp = x;
    	x = y;
    	y = temp % y;
	}
	
	return y;
}

int GCD2(const int m,const int n)
{
	int x = 0; 
	
	if (m == 0 || n == 0) {
    	return ( -1 );
    }
    
    if (m < n) {
    	x = m;
	}
   	else {
   		x = n;
	}
	
	while (m % x != 0 || n % x != 0) {
		x--;
	}
	
	return x;
}

int GCD3(const int m,const int n)
{
	void FindFactorization(int x,FACTORIZATION *factorization);
    void DisplayFactorization(const int x,const FACTORIZATION factorization);

    FACTORIZATION mFactorization;
    FACTORIZATION nFactorization;
    int r,mi,ni;
    int gcd = 01;
    
    if (m == 0 || n == 0) {
    	return ( -1 );
    }
    
	// Step 1.
    FindFactorization(m,&mFactorization);
    DisplayFactorization(m,mFactorization);
	// Step 2.
    FindFactorization(n,&nFactorization);
    DisplayFactorization(n,nFactorization);

	// Steps 3 and 4.
	for(int mi = 1; mi <= mFactorization.size; mi++) {
		for(int ni = 1; ni <= nFactorization.size; ni++) {
			if (mFactorization.factor[mi] == nFactorization.factor[ni]) {
				if (mFactorization.exponent[mi] < nFactorization.exponent[ni]) {
					gcd *= pow(mFactorization.factor[mi], mFactorization.exponent[mi]);
				}
				else {
					gcd *= pow(nFactorization.factor[ni], nFactorization.exponent[ni]);
				}
			}
		}
	}
	
	return gcd;
}

void FindFactorization(int x,FACTORIZATION *factorization)
{
	int NextPrime(int x);
	int factor = 2;
	
	(*factorization).size = 1;
	(*factorization).factor[1] = 1;
	(*factorization).exponent[1] = 1;
	
	while (x != 1) {
		int exponent = 0;
		while ( x % factor == 0 ) {
			x = x / factor;
			exponent++;
		}

        if (exponent != 0) {
            (*factorization).size++;
			(*factorization).factor[factorization->size] = factor;
			(*factorization).exponent[factorization->size] = exponent;
		}
		factor = NextPrime(factor);
	}
}

void DisplayFactorization(const int x,const FACTORIZATION factorization)
{
	printf("%d = ",x);
	for (int i = 1; i <= factorization.size; i++)
	{
    	printf("%d",factorization.factor[i]);
    	if ( factorization.exponent[i] > 1 )
        	printf("^%d",factorization.exponent[i]);
      	if ( i < factorization.size )
         	printf("*");
      	else
         	printf("\n");
   	}
}

int NextPrime(int x)
{
	bool IsPrime(const int x);

   	do
    	x++;
   	while ( !IsPrime(x) );
   	return( x );
}

bool IsPrime(const int x)
{
   	bool r = true;

   	for (int i = 2; (i <= (int) sqrt(x)) && r; i++)
      	r = r && ((x % i) != 0);
   	return( r );
}

int GCD4(const int m,const int n)
{
   	int x = 0;
	int y = 0;
	
   	if (m == 0 || n == 0) {
    	return ( -1 );
    }
    
    if (m > n) {
    	x = m;
    	y = n;
	}
   	else {
   		x = n;
    	y = m;
	}
	
	if ( x % y == 0 ) {
		return y;
	}

	return GCD4(y, x % y);
		
}
