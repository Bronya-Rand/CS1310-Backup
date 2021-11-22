//--------------------------------------------------
// Dr. Art Hanna
// Problem #15
// Problem15.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include "Random.h"

#include "Hash.h"

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   bool EQ(const void *LHS, const void *RHS);
   void DisplayHash(const HASH *hash);
   void DestructElement(const void *key, const void *record);

   char alphabet[] = "ABCDEFGHIJKLM"
                     "NOPQRSTUVWXYZ";

   HASH hash;
   int N, M, LB, UB, *record;
   long int tries;
   char *key;

   printf("N? ");
   scanf("%d", &N);
   printf("M? ");
   scanf("%d", &M);
   printf("LB? ");
   scanf("%d", &LB);
   printf("UB? ");
   scanf("%d", &UB);
   SetRandomSeed();
   ConstructHash(&hash, M, DestructElement, EQ, HashFunction_string);
   for (int i = 1; i <= N; i++)
   {
      key = (char *)malloc(sizeof(char) * (5 + 1));
      for (int j = 0; j <= 4; j++)
         key[j] = RandomChar(alphabet, (int)strlen(alphabet));
      key[5] = '\0';
      record = (int *)malloc(sizeof(int));
      *record = RandomInt(LB, UB);
      AddToHash(&hash, key, record);
   }
   DisplayHash(&hash);
   key = (char *)malloc(sizeof(char) * (5 + 1));
   tries = 0;
   do
   {
      tries++;
      for (int j = 0; j <= 4; j++)
         key[j] = RandomChar(alphabet, (int)strlen(alphabet));
      key[5] = '\0';
   } while (!IsInHash(&hash, key, (void **)&record));
   printf("Found %5s %5d after %ld tries\n", key, *record, tries);
   DestructHash(&hash);

   system("PAUSE");
   return (0);
}

//--------------------------------------------------
void DestructElement(const void *key, const void *record)
//--------------------------------------------------
{
   free((void *)key);
   free((void *)record);
}

//--------------------------------------------------
bool EQ(const void *LHS, const void *RHS)
//--------------------------------------------------
{
   return ((strcmp((char *)LHS, (char *)RHS) == 0) ? true : false);
}

//--------------------------------------------------
void DisplayElement(const int i, void *key, void *record)
//--------------------------------------------------
{
   printf("%3d: %5s %5d\n", i, (char *)key, *((int *)record));
}

//--------------------------------------------------
void DisplayHash(const HASH *hash)
//--------------------------------------------------
{
   void DisplayElement(const int i, void *key, void *record);

   printf("N = %5d\n", GetHashN(hash));
   printf("M = %5d\n", GetHashM(hash));
   TraverseHash((HASH *)hash, DisplayElement);
}
