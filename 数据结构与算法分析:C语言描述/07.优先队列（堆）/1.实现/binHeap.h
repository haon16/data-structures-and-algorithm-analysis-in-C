//2020年11月6日 20:38:29
//优先队列的实现

#ifndef _BinHeap_H

#include "../../base.h"

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

//初始化
PriorityQueue Initialize(int MaxElements);

//销毁
void Destroy(PriorityQueue H);

//置空
void MakeEmpty(PriorityQueue H);

//插入元素
void Insert(ElementType X, PriorityQueue H);

//删除最小值
ElementType DeleteMin(PriorityQueue H);

//获取最小值
ElementType FindMin(PriorityQueue H);

//判断是否为空
int IsEmpty(PriorityQueue H);

//判断是否满
int IsFull(PriorityQueue H);

//遍历输出
void PrintPriorityQueue(PriorityQueue H);

#endif      /* _BinHeap_H */

