//2020年10月27日 15:01:30
//二叉树的实现

#include <stdio.h>
#include "binaryTree.h"
#include "../../3.队列/1.实现/arrayQueue.h"

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};

Tree CreatBinaryTree()
{
    Tree T;
    char ch;
    scanf("%c", &ch);
    getchar();
    if(ch == '0')
        T = NULL;
    else
    {
        T = (Tree)malloc(sizeof(struct TreeNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        
        T->Element = ch;
        printf("请输入%c的左结点：", ch);
        T->Left = CreatBinaryTree();
        printf("请输入%c的右结点：", ch);
        T->Right = CreatBinaryTree();
    }
    return T;
}

void PreorderTraversal(Tree T)
{
    if(T == NULL)
        return;

    printf("%c ", T->Element);
    PreorderTraversal(T->Left);
    PreorderTraversal(T->Right);
}

void InorderTraversal(Tree T)
{
    if(T == NULL)
        return;

    InorderTraversal(T->Left);
    printf("%c ", T->Element);
    InorderTraversal(T->Right);
}

void PostorderTraversal(Tree T)
{
    if(T == NULL)
        return;

    PostorderTraversal(T->Left);
    PostorderTraversal(T->Right);
    printf("%c ", T->Element);
}

void LevelTraversal(Tree T)
{
    Queue Q = CreateQueue(20);
    Enqueue(T, Q);              //队列元素用的是整数，这边把地址赋值给了整数，有可能会有问题。测试环境指针占用8个字节，也就是64位地址，但实际上地址值输出占用都小于32位,有可能还没用到32位以后的吧

    while(!IsEmpty(Q))
    {
        Tree Temp = FrontAndDequeue(Q);
        printf("%c ", Temp->Element);
        printf("%p ", Temp);
        if(Temp->Left != NULL)
            Enqueue(Temp->Left, Q);
        if(Temp->Right != NULL)
            Enqueue(Temp->Right, Q);
    }
    printf("\n");
    DisposeQueue(Q);
}

int Depth(Tree T)
{
    if(T == NULL)
        return 0;
    
    return 1 + Max(Depth(T->Left), Depth(T->Right));
}