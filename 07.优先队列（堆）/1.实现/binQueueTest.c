//2020年11月17日 18:52:24
//测试二项队列

#include <stdio.h>
#include "binQueue.h"

int main()
{
    BinQueue H = Initialize();
    Insert(1, H);
    Insert(3, H);
    Insert(2, H);
    Insert(5, H);
    Insert(6, H);
    Insert(4, H);
    PrintBinHeap(H);

    printf("删除最小元素：%d\n", DeleteMin(H));
    printf("删除最小元素：%d\n", DeleteMin(H));
    PrintBinHeap(H);

    Destroy(H);
    return 0;
}