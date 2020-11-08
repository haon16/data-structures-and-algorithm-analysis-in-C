//2020年11月8日 11:40:58
//分离链接散列表的实现

#ifndef _HashSep_H

#include "../../base.h"

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

typedef unsigned int Index;

Index Hash(ElementType Key, int TableSize);

int NextPrime(int Num);

HashTable InitializeTable(int TableSize);

void DestroyTable(HashTable H);

Position Find(ElementType Key, HashTable H);

void Insert(ElementType Key, HashTable H);

void Delete(ElementType Key, HashTable H);

ElementType Retrieve(Position P);

int GetHashTableSize(HashTable H);

void PrintHashTable(HashTable H);

#endif      /* _HashSep_H */