//2020年11月9日 21:07:50
//测试二叉堆

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binHeap.h"

int main()
{
    srand(time(NULL));
    PriorityQueue H = Initialize(20);
    for(int i = 0; i < 20; i++)
        Insert(rand() % 20 + 1, H);
    
    PrintPriorityQueue(H);
    printf("最小值：%d\n", FindMin(H));

    DeleteMin(H);
    PrintPriorityQueue(H);

    Insert(rand() % 20 + 1, H);
    PrintPriorityQueue(H);

    Destroy(H);
    return 0;
}