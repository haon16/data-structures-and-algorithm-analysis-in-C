//2020年10月28日23点11分
//测试二叉查找树

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "searchTree.h"

int main()
{
    srand((unsigned)time(NULL));
    SearchTree T = NULL;
    MakeEmpty(T);
    for(int i = 0; i < 10; i++)
        T = Insert(rand()%100, T);                  //每次插入新元素后都要记得重新赋值给T

    printf("中序遍历结果：");
    InorderTraversal(T);
    printf("\n");

    printf("max:%d\n", Retrieve(FindMax(T)));       //结构体是在.c源文件定义的，只包含头文件的话无法获取结构体的成员，所以不能直接用指针取成员
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