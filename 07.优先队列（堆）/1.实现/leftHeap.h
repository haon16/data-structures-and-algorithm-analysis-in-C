//2020年11月10日 10:29:34
//左式堆的实现

#ifndef _LeftHeap_H
#define _LeftHeap_H

#include "../../base.h"

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

//初始化
PriorityQueue Initialize();

//寻找最小值
ElementType FindMin(PriorityQueue H);

//是否为空
int IsPriorityQueueEmpty(PriorityQueue H);

//合并
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))
#define DeleteMin(H) (H = DeleteMin1(H))

//插入
PriorityQueue Insert1(ElementType X, PriorityQueue H);

//删除最小值
PriorityQueue DeleteMin1(PriorityQueue H);

//输出
void PrintPriorityQueue(PriorityQueue H);

#endif      /* _LeftHeap_H */