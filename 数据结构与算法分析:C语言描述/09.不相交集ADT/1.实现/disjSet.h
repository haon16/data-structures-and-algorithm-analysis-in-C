//2020年11月21日 10:51:01
//不相交集合实现

#ifndef _DisjSet_H

#include "../../base.h"

#define NumSets 10

typedef int DisjSet[NumSets + 1];
typedef int SetType;

//初始化
void Initialize(DisjSet S);

//合并
void SetUnion(DisjSet S, SetType Root1, SetType Root2);

//查找
SetType Find(ElementType X, DisjSet S);

//遍历输出
void PrintDisjSet(DisjSet S);

#endif      /* _DisjSet_H */