//2020年11月10日 10:48:23
//左式堆的实现

#include <stdio.h>
#include <stdlib.h>
#include "leftHeap.h"
#include "../../04.队列/1.实现/arrayQueue.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};


PriorityQueue Initialize()
{
    PriorityQueue H = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if(H == NULL)
        FatalError("Out of space!!!");
    
    H->Left = H->Right = NULL;
    H->Npl = 0;
    H->Element = -1;

    return H;
}

int IsPriorityQueueEmpty(PriorityQueue H)
{
    return H->Left == NULL && H->Right == NULL;
}

ElementType FindMin(PriorityQueue H)
{
    if(!IsPriorityQueueEmpty(H))
        return H->Element;
    
    Error("Priority queue is empty");
    return 0;
}

static void SwapChildren(PriorityQueue H)
{
    PriorityQueue Temp = H->Left;
    H->Left = H->Right;
    H->Right = Temp;
}

//合并左式堆的实际函数
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if(H1->Left == NULL)    //单结点(H1->Right == NULL,H1->Npl == 0)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if(H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        
        H1->Npl = H1->Right->Npl + 1;
    }

    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if(H1 == NULL)
        return H2;
    if(H2 == NULL)
        return H1;
    if(H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        FatalError("Out of space!!!");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    if(IsPriorityQueueEmpty(H))
        Error("Priority queue is empty");
    
    PriorityQueue LeftHeap = H->Left;
    PriorityQueue RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

void PrintPriorityQueue(PriorityQueue H)
{
    if(H == NULL)
        return;
    
    Queue Q = CreateQueue(20);
    Enqueue(H, Q);

    while(!IsEmpty(Q))
    {
        PriorityQueue H = FrontAndDequeue(Q);

        printf("%d\n", H->Element);
        if(H->Left != NULL)
            Enqueue(H->Left, Q);
        else
            printf("%d的左边为NULL\n", H->Element);
        
        if(H->Right != NULL)
            Enqueue(H->Right, Q);
        else
            printf("%d的右边为NULL\n", H->Element);
    }
    printf("\n");
}