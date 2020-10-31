//2020年10月26日 20:33:59
//队列的数组实现

#include <stdio.h>
#include "arrayQueue.h"

#define MinQueueSize 5

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    if(MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        FatalError("Out of space!!!");
    
    Q->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
    if(Q->Array == NULL)
        FatalError("Out of space!!!");
    
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{   
    if(IsFull(Q))
        Error("Full queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty queue");
    else
        return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty queue");
    else
    {
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X;
    if(IsEmpty(Q))
        Error("Empty queue");
    else
    {
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
        Q->Size--;
    }
    
    return X;
}

void PrintQueue(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is Empty\n");
        return;
    }
    
    int i = Q->Front;
    while(i != Q->Rear)
    {
        printf("%d ", Q->Array[i]);
        i = Succ(i, Q);
    }
    printf("%d\n", Q->Array[Q->Rear]);
}