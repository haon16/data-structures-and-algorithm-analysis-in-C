//2020年11月8日 11:40:58
//分离链接散列表的实现

#ifndef _HashSep_H
#define _HashSep_H

#include "../../base.h"

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

typedef unsigned int Index;

//散列函数
Index Hash(ElementType Key, int TableSize);

//寻找大于等于Num的最近一个素数
int NextPrime(int Num);

//初始化
HashTable InitializeTable(int TableSize);

//销毁
void DestroyTable(HashTable H);

//查找
Position Find(ElementType Key, HashTable H);

//插入
void Insert(ElementType Key, HashTable H);

//删除
void Delete(ElementType Key, HashTable H);

//指定结点的元素
ElementType Retrieve(Position P);

//表的大小
int GetHashTableSize(HashTable H);

//输出
void PrintHashTable(HashTable H);

#endif      /* _HashSep_H */