//2020年11月1日22点05分
//测试AVL树（同二叉查找树）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVLTree.h"

int main()
{
    srand((unsigned)time(NULL));
    AvlTree T = NULL;
    MakeEmpty(T);
    for(int i = 0; i < 10; i++)
        T = Insert(rand()%100, T);                  

    printf("中序遍历结果：");
    InorderTraversal(T);
    printf("\n");

    printf("max:%d\n", Retrieve(FindMax(T)));  
    printf("min:%d\n", Retrieve(FindMin(T)));

    int X = rand()%100;
    Position P = Find(X, T);
    if(P == NULL)
        printf("树中不存在元素%d\n", X);
    else
        printf("树中存在元素%d\n", X);

    //T = Delete(1, T);
    T = Delete(Retrieve(T), T);
    T = Delete(Retrieve(T), T);
    printf("中序遍历结果：");
    InorderTraversal(T);
    printf("\n");

    return 0;
}