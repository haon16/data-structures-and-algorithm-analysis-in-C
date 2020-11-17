//2020年11月17日 15:53:00
//二项队列的实现

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binQueue.h"

#define MaxTrees 8
#define Capacity 20

//树
struct BinNode
{
    ElementType Element;
    Position LeftChild;
    Position NextSibling;
};

//森林
struct Collection
{
    int CurrentSize;                //结点个数
    BinTree TheTrees[MaxTrees];     //每个元素都是一课二项树
};

int IsEmpty(BinQueue H)
{
    return H->CurrentSize == 0;
}

BinQueue Initialize()
{
    BinQueue H = (BinQueue)malloc(sizeof(struct Collection));
    if(H == NULL)
        FatalError("Out of space!!!");

    H->CurrentSize = 0;
    for(int i = 0; i < MaxTrees; ++i)
    {
        H->TheTrees[i] = NULL;
    }
    return H;
}

static void DestroyTree(BinTree T)
{
    if(T != NULL)
    {
        DestroyTree(T->LeftChild);
        DestroyTree(T->NextSibling);
        free(T);
    }
}

void Destroy(BinQueue H)
{
    for(int i = 0; i < MaxTrees; ++i)
        DestroyTree(H->TheTrees[i]);
    
    free(H);
}

BinQueue MakeEmpty(BinQueue H)
{
    for(int i = 0; i < MaxTrees; ++i)
        DestroyTree(H->TheTrees[i]);

    H->CurrentSize = 0;
    return H;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if(T1->Element > T2->Element)
        return CombineTrees(T2, T1);

    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    if(H1->CurrentSize + H2->CurrentSize > Capacity)
        Error("Merger would exceed capacity");

    H1->CurrentSize += H2->CurrentSize;
    for(int i = 0, j = 1; j <= H1->CurrentSize; i++, j*=2)
    {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        switch(!!T1 + 2 * !!T2 + 4 * !!Carry)   //存在与否
        {
            case 0: /* No trees */
            case 1: /* Only H1 */
                break;
            case 2: /* Only H2 */
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4: /* Only Carry */
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 3: /* H1 and H2 */
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                break;
            case 5: /* H1 and Carry */
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6: /* H2 and Carry */
                Carry = CombineTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7: /* All three */
                H1->TheTrees[i] = Carry;
                Carry = CombineTrees(T1, T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
    return H1;
}

BinQueue Insert(ElementType Item, BinQueue H)
{
    BinTree NewNode = (BinTree)malloc(sizeof(struct BinNode));
    if(NewNode == NULL)
        FatalError("Out of space!!!");
    NewNode->Element = Item;
    NewNode->LeftChild = NewNode->NextSibling = NULL;
    
    BinQueue OneItem = Initialize();
    OneItem->CurrentSize = 1;
    OneItem->TheTrees[0] = NewNode;

    return Merge(H, OneItem);
}

ElementType DeleteMin(BinQueue H)
{
    if(IsEmpty(H))
        Error("Empty binomial queue");

    int MinTree;        /*the tree with the minimum item*/
    ElementType MinItem = INT_MAX;
    for(int i = 0; i < MaxTrees; i++)
    {
        if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
        {
            /* Update minimum */
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }

    Position DeletedTree = H->TheTrees[MinTree];
    Position OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);

    BinQueue DeletedQueue = Initialize();
    DeletedQueue->CurrentSize = (1 << MinTree) - 1;     //将1左移MinTree位，即可得到高度为MinTree的二项树的大小，高度为K的二项树的大小为2^k，减1是因为删除了根

    for(int j = MinTree - 1; j >= 0; j--)               //删除根后的各个子树构成新的二项队列
    {
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL;
    }

    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;

    Merge(H, DeletedQueue);
    return MinItem;
}

static void PrintTree(BinTree T)
{
    if(T != NULL)
    {
        printf("%d\n", T->Element);
        if(T->LeftChild == NULL)
            printf("%d的左子树为空\n", T->Element);
        else
            PrintTree(T->LeftChild);

        if(T->NextSibling == NULL)
            printf("%d的右子树为空\n", T->Element);
        else
            PrintTree(T->NextSibling);
    }
}

void PrintBinHeap(BinQueue H)
{
    for(int i = 0; i < MaxTrees; i++)
    {
        if(H->TheTrees[i] == NULL)
            printf("[%d]为空\n", i);
        else
            PrintTree(H->TheTrees[i]);
    }
}