//2020年11月10日 17:52:07
//测试左式堆

#include <stdio.h>
#include "leftHeap.h"

int main()
{
    PriorityQueue H1 = Initialize();
    Insert(1, H1);
    Insert(3, H1);
    Insert(2, H1);
    Insert(7, H1);
    PrintPriorityQueue(H1);

    PriorityQueue H2 = Initialize();
    Insert(4, H2);
    Insert(3, H2);
    Insert(5, H2);
    Insert(6, H2);
    PrintPriorityQueue(H2);

    H1 = Merge(H1, H2);
    printf("合并后：\n");
    PrintPriorityQueue(H1);

    DeleteMin(H1);
    printf("删除最小值后：\n");
    PrintPriorityQueue(H1);
}