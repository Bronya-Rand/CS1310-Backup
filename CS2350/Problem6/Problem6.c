//------------------------------------------------------
// Dr. Art Hanna
// Problem #6
// Problem6.c
//------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAXIMUMM 512
#define MAXIMUMR  10

typedef char BITS[MAXIMUMM+MAXIMUMR+1];
typedef enum { EVEN,ODD } PARITY;

//------------------------------------------------------
int main()
//------------------------------------------------------
{
   void ComputeCodeWord(const BITS memoryWord,const PARITY parity,
                        int *m,int *r,BITS codeWord,BITS hammingCode);
   void SetRandomSeed(void);
   int RandomInt(const int LB,const int UB);
   void ToggleBit(BITS word,const int bit);
   void CorrectSingleBitError(const PARITY parity,const int m,const int r,BITS codeWord);

   char fileName[80+1];
   FILE *MEMORYWORDS;
   BITS memoryWord,codeWord,hammingCode;
   PARITY parity;
   int m,r,n,bit;

   printf("memory-words fileName? "); scanf("%s",fileName);
   if ( (MEMORYWORDS = fopen(fileName,"r")) == NULL)
   {
      printf("Error opening memory-words file \"%s\"!\n",fileName);
      system("PAUSE");
      exit( 1 );
   }

   SetRandomSeed();

   while ( fgets(&memoryWord[1],MAXIMUMM,MEMORYWORDS) != NULL )
   {
   /*
      To ensure that ignoring memoryWord[0] can be done "safely", set memoryWord[0] to some
         innocuous value. *Note* Thanks to both Breanne Ludovice and Alex Montes (Spring 2018)
         for help in diagnosing and subsequently fixing this long-standing bug!?
   */
      memoryWord[0] = 'X';

   // Ignore memoryWord[0], erase '\n' at end of memoryWord[] string (if any)
      if ( memoryWord[strlen(memoryWord)-1] == '\n' )
         memoryWord[strlen(memoryWord)-1] = '\0';

   /*
      Determine and erase parity at end of memoryWord[] string (if any)--an 'E' or 'e'
         suffix means (E)VEN, 'O' or 'o' suffix means (O)DD, and no suffix defaults to EVEN.
      Here's BNF (Backus-Naur Form) that captures the preceding description of a memoryWord[]
         <memoryWord> ::= <bit> { <bit> }* [ (( E | e | O | o )) ]
         <bit>        ::= 0 | 1
   */
      if      ( toupper(memoryWord[strlen(memoryWord)-1]) == 'E' )
      {
         parity = EVEN;
         memoryWord[strlen(memoryWord)-1] = '\0';
      }
      else if ( toupper(memoryWord[strlen(memoryWord)-1]) == 'O' )
      {
         parity = ODD;
         memoryWord[strlen(memoryWord)-1] = '\0';
      }
      else
         parity = EVEN;

   // Compute hammingCode[], codeWord[], m, and r based on parity, memoryWord[]
      ComputeCodeWord(memoryWord,parity,&m,&r,codeWord,hammingCode);
   /* 
      Display memoryWord[], hammingCode[], and codeWord[]. *Note* Colin Strong
         (Spring 2019 ) suggested that the Hamming code bits should be displayed.
   */
      printf("\n");
      printf("Memory word  = %s%c\n",&memoryWord[1],((parity == EVEN) ? 'E' : 'O'));
      printf("Hamming code = %s\n",&hammingCode[1]);
      printf("Code word    = %s original\n",&codeWord[1]);

   /* 
      Cause a random, single-bit error then show the erroneous codeWord[]; 
         correct the single-bit error; display corrected codeWord[]
   */
      n = m+r;
      bit = RandomInt(1,n);
      ToggleBit(codeWord,bit);
      printf("Code word    = %s with error in bit #%d\n",&codeWord[1],bit);
      CorrectSingleBitError(parity,m,r,codeWord);
      printf("Code word    = %s with error corrected\n", &codeWord[1]);
   }
   fclose(MEMORYWORDS);

   system("PAUSE");
   return( 0 );
}

//------------------------------------------------------
void ComputeCodeWord(const BITS memoryWord,const PARITY parity,
                     int *m,int *r,BITS codeWord,BITS hammingCode)
//------------------------------------------------------
{
   int R(const int m);
   bool IsPowerOf2(const int x);
   int PowerOf2(const int exponent);
   void ComputeHammingCode(const BITS codeWord,const PARITY parity,
                           const int m,const int r,BITS hammingCode);

   int n,ri,mi,ci;

// Compute m, r, n
   *m = strlen(memoryWord)-1;
   *r = R(*m);
   n = *m + *r;

/*
   Place memoryWord[] bits into codeWord[] leaving room for the hammingCode[]
      bits which are temporarily marked 'H'
*/
   mi = 1;
   for (ci = 1; ci <= n; ci++)
   {
      if ( IsPowerOf2(ci) )
         codeWord[ci] = 'H';
      else
      {
         codeWord[ci] = memoryWord[mi];
         mi++;
      }
   }
   codeWord[n+1] = '\0';

// Place hammingCode[] bits into codeWord[] thereby overwriting each 'H'
   ComputeHammingCode(codeWord,parity,*m,*r,hammingCode);
   for (ri = 1; ri <= *r; ri++)
      codeWord[PowerOf2(ri-1)] = hammingCode[ri];
}

//------------------------------------------------------
void ComputeHammingCode(const BITS codeWord,const PARITY parity,
                        const int m,const int r,BITS hammingCode)
//------------------------------------------------------
{
   bool IsPowerOf2(const int x);
   int PowerOf2(const int exponent);

   int n = m+r;
   int *sums = (int *) malloc(sizeof(int)*(r+1));
   int ri,ci;

// Compute sum-of-bits for each hammingCode[] bit
   for (ri = 1; ri <= r; ri++)
      sums[ri] = 0;
   for (ri = 1; ri <= r; ri++)
      for (ci = PowerOf2(ri-1); ci <= n; ci++)
         if ( !IsPowerOf2(ci) )
            if ( ((ci >> (ri-1)) & 0X1) == 1 ) sums[ri] += (codeWord[ci] == '1') ? 1 : 0;

// Compute hammingCode[] bits for EVEN or ODD parity
   for (ri = 1; ri <= r; ri++)
      if ( sums[ri]%2 == 0 )
         hammingCode[ri] = (parity == EVEN) ? '0' : '1';
      else
         hammingCode[ri] = (parity == EVEN) ? '1' : '0';
   hammingCode[r+1] = '\0';
   free(sums);
}

//------------------------------------------------------
void CorrectSingleBitError(const PARITY parity,const int m,const int r,BITS codeWord)
//------------------------------------------------------
{
   void ComputeHammingCode(const BITS codeWord,const PARITY parity,
                           const int m,const int r,BITS hammingCode);
   int PowerOf2(const int exponent);
   void ToggleBit(BITS word,const int bit);

   int ri,bit;
   BITS hammingCode;

// Compute hammingCode[] bits
   ComputeHammingCode(codeWord,parity,m,r,hammingCode);

// Compare computed hammingCode[] bits to codeWord[] bits to determine single incorrect bit
   bit = 0;
   for (ri = 1; ri <= r; ri++)
   {
      int ci = PowerOf2(ri-1);

      if ( codeWord[ci] != hammingCode[ri] ) bit += ci;
   }

// Toggle incorrect bit
   ToggleBit(codeWord,bit);
}

//------------------------------------------------------
int R(const int m)
//------------------------------------------------------
{
   int PowerOf2(const int exponent);

   int r = 1;

   while ( (m+r+1) > PowerOf2(r) ) r++;
   return( r );
}

//------------------------------------------------------
int PowerOf2(const int exponent)
//------------------------------------------------------
{
   return( (int) pow(2,exponent) );
}

//------------------------------------------------------
bool IsPowerOf2(const int x)
//------------------------------------------------------
{
   int powerOf2 = 1;

   while ( powerOf2 < x )
      powerOf2 *= 2;
   return( (powerOf2 == x) ? true : false );
}

//------------------------------------------------------
void ToggleBit(BITS word,const int bit)
//------------------------------------------------------
{
   word[bit] = (word[bit] == '1') ? '0' : '1';
}

//-----------------------------------------------------
// Functions below are "stolen" from the Dr. Hanna random-related pseudo-library
//-----------------------------------------------------
void SetRandomSeed(void)
//-----------------------------------------------------
{
   srand( (unsigned int) time(NULL) );
}

//------------------------------------------------------
int RandomInt(const int LB,const int UB)
//------------------------------------------------------
{
   double RandomDouble();

   return( (int) ((UB-LB+1)*RandomDouble()) + LB );
}

//--------------------------------------------------
double RandomDouble()
//--------------------------------------------------
{
   int R;

   do
      R = rand();
   while ( R == RAND_MAX );
   return( (double) R/RAND_MAX );
}
