//2020年11月10日 10:29:34
//左式堆的实现

#ifndef _LeftHeap_H
#define _LeftHeap_H

#include "../../base.h"

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initialize();

ElementType FindMin(PriorityQueue H);

int IsPriorityQueueEmpty(PriorityQueue H);

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))
#define DeleteMin(H) (H = DeleteMin1(H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);

PriorityQueue DeleteMin1(PriorityQueue H);

void PrintPriorityQueue(PriorityQueue H);

#endif      /* _LeftHeap_H */