//2020年10月28日21点53分
//二叉查找树的实现

#include <stdio.h>
#include "searchTree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
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

Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if(T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } 
    else if(X < T->Element)
        T->Left = Insert(X, T->Left);
    else if(X > T->Element)
        T->Right = Insert(X, T->Right);
    else
        printf("元素%d插入失败，树中已存在该元素\n", X);

    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position Temp;

    if(T == NULL)
        Error("Element not fount");
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
        T->Right = Delete(X, T->Right);
    else if(T->Left && T->Right)    //找到指定元素且左右子树都存在
    {
        Temp = FindMin(T->Right);
        T->Element = Temp->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else    //有0个或1个子树
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

void InorderTraversal(SearchTree T)
{
    if(T == NULL)
        return;

    InorderTraversal(T->Left);
    printf("%d ", T->Element);
    InorderTraversal(T->Right);
}