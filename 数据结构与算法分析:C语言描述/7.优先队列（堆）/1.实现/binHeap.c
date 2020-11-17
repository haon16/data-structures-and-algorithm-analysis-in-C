//2020年11月6日 20:57:37
//优先队列的实现

#include <stdio.h>
#include <stdlib.h>
#include "binHeap.h" 

#define MinPQSize 10
#define MinData -1

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
    if(MaxElements < MinPQSize)
        Error("Priority queue size is too small");
    
    PriorityQueue H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if(H == NULL)
        FatalError("Out of space!!!");
    
    H->Elements = (ElementType *)malloc((MaxElements + 1) * sizeof(ElementType));
    if(H->Elements == NULL)
        FatalError("Out of space!!!");
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;           //把一个很小的值放到位置0处以使循环得以终止，这个值必须保证小于或等于堆中的任何值，我们称之为标记
                                        //通过一条哑信息，避免了每个循环都要执行一次的测试，从而节省了一些时间
    return H;
}

void Destroy(PriorityQueue H)
{
    if(H != NULL)
    {
        free(H->Elements);
        free(H);
    }
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H)
{
    if(IsFull(H))
        Error("Priority queue is full");
    
    int i;
    for(i = ++H->Size; H->Elements[i/2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
    if(IsEmpty(H))
        Error("Priority queue is empty");
    
    ElementType MinElement = H->Elements[1];
    ElementType LastElement = H->Elements[H->Size--];
    int i, Child;

    for(i = 1; i*2 <= H->Size; i = Child)
    {
        //寻找最小的子结点
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;

    return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
    if(IsEmpty(H))
        Error("Priority queue is empty");
    
    return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

void PrintPriorityQueue(PriorityQueue H)
{
    for(int i = 1; i < H->Size; i++)
    {
        printf("%d ", H->Elements[i]);
    }
    printf("\n");
}