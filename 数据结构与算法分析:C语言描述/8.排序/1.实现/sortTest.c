//2020年11月18日 10:29:04
//排序测试

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define N 20

int main()
{
    srand((unsigned)time(NULL));
    ElementType A[N] = {0};
    for(int i = 0; i < N; i++)
    {
        A[i] = rand() % 100 - 10;
    }
    printf("生成的随机数组：");
    PrintArray(A, N);

    typedef void (*Fun)(ElementType A[], int Length);
    Fun ArrayFun[] = 
    {
        BubbleSort,
        SelectSort,
        InsertionSort,
        ShellSort,
        HeapSort,
        MergeSort,
        QuickSort,
        BucketSort,
        CountingSort,
        RadixSort
    };
    char *SortName[] = {"冒泡排序", "选择排序", "插入排序", "希尔排序", "堆排序", "归并排序", "快速排序", "桶排序", "计数排序", "基数排序"};
    int size = sizeof(ArrayFun) / sizeof(ArrayFun[0]);

    for(int i = 0; i < size; i++)
    {
        RandomShuffle(A, N);
        //printf("打乱顺序：");
        //PrintArray(A, N);
        ArrayFun[i](A, N);
        printf("%s结果：", SortName[i]);
        PrintArray(A, N);
        printf("\n");
    }
   
    RandomShuffle(A, N);
    printf("打乱顺序：");
    PrintArray(A, N);

    int kth = 5;
    int val = QuickSelect(A, N, kth);
    printf("快速选择结果：");
    PrintArray(A, N);
    printf("第%d个最小值是%d\n", kth, val);

    return 0;
}


