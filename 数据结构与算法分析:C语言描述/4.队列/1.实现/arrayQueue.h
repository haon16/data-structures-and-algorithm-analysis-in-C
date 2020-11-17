//2020年10月26日 20:27:07
//队列的数组实现

#ifndef _ArrayQueue_H

#include "../../base.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;

//队列是否为空
int IsEmpty(Queue Q);

//队列是否满
int IsFull(Queue Q);

//创建队列
Queue CreateQueue(int MaxElements);

//销毁队列
void DisposeQueue(Queue Q);

//构造空队列
void MakeEmpty(Queue Q);

//入队
void Enqueue(ElementType X, Queue Q);

//队列首元素
ElementType Front(Queue Q);

//出队
void Dequeue(Queue Q);

//出队并返回首元素
ElementType FrontAndDequeue(Queue Q);

//遍历输出队列元素
void PrintQueue(Queue Q);

#endif      /* _ArrayQueue_H */