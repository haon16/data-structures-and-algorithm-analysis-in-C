//2020年11月4日 10:56:34
//开放定址散列表的实现

#ifndef _HashQuad_H
#define _HashQuad_H

#include "../../base.h"

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

//散列函数
Index Hash(ElementType Key, int TableSize);

//寻找大于等于Num的最近一个素数
int NextPrime(int Num);

//初始化开放定址散列表
HashTable InitializeTable(int TableSize);

//销毁散列表
void DestroyTable(HashTable H);

//使用平方探测散列法的查找函数      （平方探测是消除线性探测中一次聚集问题的冲突解决方法）
Position Find(ElementType Key, HashTable H);

//使用平方探测散列表的插入函数
void Insert(ElementType Key, HashTable *H);

//返回指定位置的元素
ElementType Retrieve(Position P, HashTable H);

//对开放定址散列表的再散列
HashTable Rehash(HashTable H);

//获取散列表当前装填因子
int GetElementRate(HashTable H);

//表的大小
int GetHashTableSize(HashTable H);

//输出
void PrintHashTable(HashTable H);

#endif      /* _HashQuad_H */