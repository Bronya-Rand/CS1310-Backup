//--------------------------------------------------
// Dr. Art Hanna
// Function definition file for HASH ADT
// Hash.c
//--------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include <math.h>
#include <assert.h>

#include "Hash.h"

//--------------------------------------------------
static bool IsPrime(const int x)
//--------------------------------------------------
{
   int i;
   bool r = true;

   i = 2;
   while ((i <= sqrt(x)) && (r))
   {
      r = r && (x % i != 0);
      i++;
   }
   return (r);
}

//--------------------------------------------------
static int NextPrime(const int x)
//--------------------------------------------------
{
   int r;

   r = x;
   do
      r++;
   while (!IsPrime(r));
   return (r);
}

//--------------------------------------------------
void ConstructHash(HASH *hash, const int M,
                   void (*DestructElement)(const void *key, const void *record),
                   bool (*EQ)(const void *LHS, const void *RHS),
                   int (*HashFunction)(const HASH *hash, const void *key))
//--------------------------------------------------
{
   assert(EQ != NULL);
   assert(HashFunction != NULL);

   hash->N = 0;
   hash->M = (IsPrime(M) ? M : NextPrime(M));
   hash->hashTable = (HASHHEAD *)malloc(hash->M * sizeof(HASHHEAD));
   for (int i = 0; i <= (hash->M - 1); i++)
   {
      hash->hashTable[i].length = 0;
      hash->hashTable[i].head = NULL;
   }
   hash->DestructElement = DestructElement;
   hash->EQ = EQ;
   hash->HashFunction = HashFunction;
}

//--------------------------------------------------
void DestructHash(HASH *hash)
//--------------------------------------------------
{
   for (int i = 0; i <= (hash->M - 1); i++)
   {
      HASHNODE *p = hash->hashTable[i].head;

      while (p != NULL)
      {
         HASHNODE *q = p;

         if (hash->DestructElement != NULL)
            hash->DestructElement(p->key, p->record);
         p = p->FLink;
         free(q);
      }
   }
   free(hash->hashTable);
}

//--------------------------------------------------
void AddToHash(HASH *hash, const void *key, const void *record)
//--------------------------------------------------
{
   int h;
   HASHNODE *p;

   p = (HASHNODE *)malloc(sizeof(HASHNODE));
   p->key = key;
   p->record = record;
   h = hash->HashFunction(hash, key);

   p->FLink = hash->hashTable[h].head;
   hash->hashTable[h].head = p;
   hash->N++;
   hash->hashTable[h].length++;
}
//--------------------------------------------------
bool IsInHash(const HASH *hash, const void *key, void **record)
//--------------------------------------------------
{
   int h;
   HASHNODE *p;
   bool found = false;
   
   h = hash->HashFunction(hash, key);
   p = hash->hashTable[h].head;

   while (p != NULL)
   {
      found = found || hash->EQ(p->key, key);
      if (found)
      {
         *record = p->record;
      }
      p = p->FLink;
   }
   return (found);
}

//--------------------------------------------------
void DeleteFromHash(HASH *hash, const void *key)
//--------------------------------------------------
{
   printf("DeleteFromHash() not implemented\n");
}

//--------------------------------------------------
int GetHashN(const HASH *hash)
//--------------------------------------------------
{
   return (hash->N);
}

//--------------------------------------------------
int GetHashM(const HASH *hash)
//--------------------------------------------------
{
   return (hash->M);
}

//--------------------------------------------------
void TraverseHash(HASH *hash,
                  void (*ProcessElement)(const int i, void *key, void *record))
//--------------------------------------------------
{
   HASHNODE *p;

   for (int i = 0; i <= hash->M - 1; i++)
   {
      p = hash->hashTable[i].head;
      while (p != NULL)
      {
         ProcessElement(i, p->key, p->record);
         p = p->FLink;
      }
   }
}

//--------------------------------------------------
int HashFunction_int(const HASH *hash, const void *key)
//--------------------------------------------------
{
   return (*((int *)key) % ((HASH *)hash)->M);
}

//--------------------------------------------------
int HashFunction_string(const HASH *hash, const void *key)
//--------------------------------------------------
{
   int h;

   h = ((char *)key)[0];
   for (int i = 1; i <= (int)strlen((char *)key) - 1; i++)
      h = (h * 256 + ((char *)key)[i]) % ((HASH *)hash)->M;
   return (h);
}
