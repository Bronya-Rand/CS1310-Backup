//--------------------------------------------------
// Dr. Art Hanna
// Header file for HASH ADT
// Hash.h
//--------------------------------------------------
#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

//==============================================================
// Data model definitions
//==============================================================
typedef struct HASHNODE
{
   void *key;
   void *record;
   struct HASHNODE *FLink;
} HASHNODE;

typedef struct HASHHEAD
{
   int length;
   HASHNODE *head;
} HASHHEAD;

typedef struct HASH
{
   int N;               // # of keys in hash table
   int M;               // size of hash table
   HASHHEAD *hashTable; // hash table
   void (*DestructElement)(const void *key, const void *record);
   bool (*EQ)(const void *LHS, const void *RHS);
   int (*HashFunction)(const struct HASH *hash, const void *key);
} HASH;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructHash(HASH *hash, const int M,
                   void (*DestructElement)(const void *key, const void *record),
                   bool (*EQ)(const void *LHS, const void *RHS),
                   int (*HashFunction)(const HASH *hash, const void *key));
void DestructHash(HASH *hash);
void AddToHash(HASH *hash, const void *key, const void *record);
bool IsInHash(const HASH *hash, const void *key, void **record);
void DeleteFromHash(HASH *hash, const void *key);
int GetHashN(const HASH *hash);
int GetHashM(const HASH *hash);
void TraverseHash(HASH *hash,
                  void (*ProcessElement)(const int i, void *key, void *record));
int HashFunction_int(const HASH *hash, const void *key);
int HashFunction_string(const HASH *hash, const void *key);

//==============================================================
// Private utility member function prototypes
//==============================================================
//static bool IsPrime(const int x);
//static int NextPrime(const int x);

#endif
