//2020年10月28日23点11分
//测试二叉查找树

#include <stdio.h>
#include "searchTree.h"

int main()
{
    SearchTree T = CreateSearchTree();
    int array[10] = {1,3,5,7,9,8,6,4,2,0};
    for(int i = 0; i < 10; i++)
        Insert(array[i], T);

    InorderTraversal(T);
    //printf("max:%d\n", FindMax(T)->Element);
    //printf("min:%d\n", FindMin(T)->Element);
}