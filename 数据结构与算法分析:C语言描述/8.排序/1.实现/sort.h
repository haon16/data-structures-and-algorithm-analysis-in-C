//2020年11月18日 10:19:10
//排序实现

#ifndef _Sort_H

#include "../../base.h"

//冒泡排序
void BubbleSort(ElementType A[], int N);

//选择排序
void SelectSort(ElementType A[], int N);

//插入排序
void InsertionSort(ElementType A[], int N);

//使用希尔增量的希尔排序
void ShellSort(ElementType A[], int N);

//堆排序
void HeapSort(ElementType A[], int N);

//归并排序
void MergeSort(ElementType A[], int N);

//快速排序
void QuickSort(ElementType A[], int N);

//快速选择（找到第k个最小元）
int QuickSelect(ElementType A[], int N, int k);

//桶排序
void BucketSort(ElementType A[], int N);

//计数排序
void CountingSort(ElementType A[], int N);

//基数排序
void RadixSort(ElementType A[], int N);

//打乱数组
void RandomShuffle(ElementType A[], int N);

//遍历输出
void PrintArray(ElementType A[], int N);

#endif      /* _Sort_H */