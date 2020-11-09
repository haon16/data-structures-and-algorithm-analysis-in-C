//2020年11月1日14点32分
//AVL树的实现（带有平衡条件的二叉查找树）

#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

int Height(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->Height;
}

AvlTree MakeEmpty(AvlTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, AvlTree T)
{
    if(T == NULL)
        return NULL;
    else if(X < T->Element)
        return Find(X, T->Left);
    else if(X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(AvlTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(AvlTree T)
{
    if(T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    
    return T;
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if(T == NULL)
    {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2)
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
            
    }
    else if(X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2)
            if(X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    else
        printf("元素%d已存在于该树中\n", X);
    
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
    Position Temp;

    if(T == NULL)
        Error("Element not fount");
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
        T->Right = Delete(X, T->Right);
    else if(T->Left && T->Right)    
    {
        Temp = FindMin(T->Right);
        T->Element = Temp->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else    
    {
        Temp = T;
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(Temp);
    }

    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void InorderTraversal(AvlTree T)
{
    if(T == NULL)
        return;

    InorderTraversal(T->Left);
    printf("%d ", T->Element);
    InorderTraversal(T->Right);
}

Position SingleRotateWithLeft(Position K2)      
{
    Position K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

    return K1;
}

Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);     //先右右单旋转，再左左单旋转

    return SingleRotateWithLeft(K3);
}

Position SingleRotateWithRight(Position K2)     
{
    Position K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

    return K1;
}

Position DoubleRotateWithRight(Position K3)
{
    K3->Right = SingleRotateWithLeft(K3->Right);    //先左左单旋转，再右右单旋转

    return SingleRotateWithRight(K3);
}