//2020年11月18日 10:19:10
//排序实现

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "sort.h"

#define LeftChild(i) (2 * i + 1)
#define Cutoff 3
#define NumOfBucket 5
#define Radix 10

static void Swap(int *a, int *b)
{
    int Temp = *a;
    *a = *b;
    *b = Temp;
}

/*-------------------------------------------------------------------------------------*/

void BubbleSort(ElementType A[], int N)
{
    int i, j, flag;
    for(i = 0; i < N-1; i++)
    {
        flag = 0;
        for(j = 0; j < N-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }

        //如果新一轮排序中元素没做过交换，说明已经是正序
        if(!flag)
            return;
    }
}

/*-------------------------------------------------------------------------------------*/

void SelectSort(ElementType A[], int N)
{
    int i, j, min;
    for(i = 0; i < N; i++)
    {
        min = i;
        for(j = i+1; j < N; j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        Swap(&A[i], &A[min]);
    }
}

/*-------------------------------------------------------------------------------------*/

void InsertionSort(ElementType A[], int N)
{
    int j, P;
    ElementType Temp;
    for(P = 1; P < N; P++)
    {
        Temp = A[P];
        for(j = P; j > 0 && A[j-1] > Temp; j--)
            A[j] = A[j-1];
        
        A[j] = Temp;
    }
}

/*-------------------------------------------------------------------------------------*/

void ShellSort(ElementType A[], int N)
{
    int i, j, Increment;
    ElementType Temp;

    for(Increment = N/2; Increment > 0; Increment /= 2)
        for(i = Increment; i < N; i++)
        {
            Temp = A[i];
            for(j = i; j >= Increment; j -= Increment)
            {
                if(Temp < A[j-Increment])
                    A[j] = A[j-Increment];
                else
                    break;
            }
            A[j] = Temp;
        }
}

/*-------------------------------------------------------------------------------------*/

static void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Temp;
    for(Temp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if(Child != N-1 && A[Child+1] > A[Child])   //左右子结点中较大者
            Child++;
        if(Temp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Temp;
}

void HeapSort(ElementType A[], int N)
{
    int i;
    for(i = N/2; i >= 0; i--)       /* BuildHeap 从最后一个非叶子节点开始*/
        PercDown(A, i, N);
    
    for(i = N - 1; i > 0; i--)
    {
        Swap(&A[i], &A[0]);         /* DeleteMax */
        PercDown(A, 0, i);
    }
}

/*-------------------------------------------------------------------------------------*/

static void Merge(ElementType A[], ElementType TempArray[], int Lpos, int Rpos, int RightEnd)
{
    int LeftEnd = Rpos - 1;
    int TempPos = Lpos;
    int NumElements = RightEnd - Lpos + 1;

    while(Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if(A[Lpos] <= A[Rpos])
            TempArray[TempPos++] = A[Lpos++];
        else
            TempArray[TempPos++] = A[Rpos++];
    }

    while(Lpos <= LeftEnd)
        TempArray[TempPos++] = A[Lpos++];
    while(Rpos <= RightEnd)
        TempArray[TempPos++] = A[Rpos++];

    for(int i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TempArray[RightEnd];
}

static void MSort(ElementType A[], ElementType TempArray[], int Left, int Right)
{
    if(Left >= Right)
        return;
    
    int Center = (Left + Right) / 2;
    MSort(A, TempArray, Left, Center);
    MSort(A, TempArray, Center+1, Right);
    Merge(A, TempArray, Left, Center+1, Right);
}

void MergeSort(ElementType A[], int N)
{
    ElementType *TempArray = (ElementType*)malloc(N * sizeof(ElementType));
    if(TempArray != NULL)
    {
        MSort(A, TempArray, 0, N-1);
        free(TempArray);
    }
    else
        FatalError("No space for temp array!!!");
}

/*-------------------------------------------------------------------------------------*/

//三数中值分割方法
static ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    /* A[Left] <= A[Center] <= A[Right] */

    Swap(&A[Center], &A[Right-1]);  /* Hide pivot */
    return A[Right-1];              /* Return pivot */
}

static void QSort(ElementType A[], int Left, int Right)
{
    ElementType Piovt;
    
    if(Left + Cutoff <= Right)
    {
        Piovt = Median3(A, Left, Right);
        int i = Left;
        int j = Right - 1;
        for(; ; )
        {
            while(A[++i] < Piovt) {}
            while(A[--j] > Piovt) {}
            if(i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right-1]);       /* Restore pivot */

        QSort(A, Left, i-1);
        QSort(A, i+1, Right);
    }
    else
    {
        InsertionSort(A+Left, Right-Left+1);
    }
}

void QuickSort(ElementType A[], int N)
{
    QSort(A, 0, N-1);
}

/*-------------------------------------------------------------------------------------*/

static void QSelect(ElementType A[], int k, int Left, int Right)
{
    ElementType Piovt;
    
    if(Left + Cutoff <= Right)
    {
        Piovt = Median3(A, Left, Right);
        int i = Left;
        int j = Right - 1;
        for(; ; )
        {
            while(A[++i] < Piovt) {}
            while(A[--j] > Piovt) {}
            if(i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right-1]);

        if(k <= i)
            QSelect(A, k, Left, i-1);
        else if(k > i + 1)
            QSelect(A, k, i+1, Right);
        // k=i+1时枢纽元就是第k个最小元
    }
    else
    {
        InsertionSort(A+Left, Right-Left+1);
    }
}

int QuickSelect(ElementType A[], int N, int k)
{
    QSelect(A, k, 0, N-1);
    return A[k-1];
}

/*-------------------------------------------------------------------------------------*/

static void BSort(ElementType A[], int N, int BucketNum)
{
    int i, j;

    //根据最大/最小元素和桶数量，计算出每个桶对应的元素范围
    int max = A[0], min = A[0];
    for(i = 0; i < N; i++)
    {
        if(A[i] > max)  max = A[i];
        if(A[i] < min)  min = A[i];
    }
    int range = (max - min + 1) / BucketNum + 1;

    //建立桶对应的二维数组，一个桶里最多可能出现N个元素
    int buckets[BucketNum][N];
    memset(buckets, 0, sizeof(buckets));
    int counts[BucketNum];
    memset(counts, 0, sizeof(counts));
    for(i = 0; i < N; i++)
    {
        int k = (A[i] - min) / range;
        buckets[k][counts[k]++] = A[i];
    }

    //分别对每个非空桶内数据进行排序，之后拼接非空的桶内数据得到最终结果
    int index = 0;
    for(i = 0; i < BucketNum; i++)
    {
        if(counts[i] == 0)
            continue;
        
        InsertionSort(buckets[i], counts[i]);
        for(j = 0; j < counts[i]; j++)
            A[index++] = buckets[i][j];
    }
}

void BucketSort(ElementType A[], int N)
{
    BSort(A, N, NumOfBucket);
}

/*-------------------------------------------------------------------------------------*/

void CountingSort(ElementType A[], int N)
{
    int i;
    
    //根据数值区间定义辅助数组
    int max = A[0], min = A[0];
    for(i = 0; i < N; i++)
    {
        if(A[i] > max)  max = A[i];
        if(A[i] < min)  min = A[i];
    }
    int Num = max - min + 1;
    int bucket[Num];
    memset(bucket, 0, sizeof(bucket));

    //统计每个元素出现的个数
    for(i = 0; i < N; i++)
        bucket[A[i] - min]++;

    //该位置的元素及左边所有元素的个数总和（小于等于该数的元素总和）
    for(i = 1; i < Num; i++)
        bucket[i] += bucket[i-1];

    //根据位置信息排序传入目标数组
    int R[N];
    for(i = 0; i < N; i++)
        R[--bucket[A[i]-min]] = A[i];

    for(i = 0; i < N; i++)
        A[i] = R[i];
}

/*-------------------------------------------------------------------------------------*/

void RadixSort(ElementType A[], int N)
{
    int i, j, l;
    int max = A[0], min = A[0];
    for(i = 0; i < N; i++)
    {
        if(A[i] > max)  max = A[i];
        if(A[i] < min)  min = A[i];
    }
    //假如数组中有负数，调整使所有值变成正数
    if(min < 0)
    {
        for(i = 0; i < N; i++)
            A[i] -= min;
        max -= min;
    }

    //获取最大值位数
    int d = 0;
    while(max > 0)
    {
        max /= Radix;
        d++;
    }

    int queue[Radix][N];
    memset(queue, 0, sizeof(queue));
    int count[Radix] = {0};
    for(i = 0; i < d; i++)
    {
        //分配数据
        for(j = 0; j < N; j++)
        {
            int key = A[j] % (int)pow(Radix, i+1) / (int)pow(Radix, i);
            queue[key][count[key]++] = A[j];
        }

        //收集数据
        int c = 0;
        for(j = 0; j < Radix; j++)
        {
            for(l = 0; l < count[j]; l++)
            {
                A[c++] = queue[j][l];
                queue[j][l] = 0;
            }
            count[j] = 0;
        }
    }

    //假如数组中有负数，收集排序结果时再减去前面加上的常数
    if(min < 0)
    {
        for(i = 0; i < N; i++)
            A[i] += min;
    }
} 

/*-------------------------------------------------------------------------------------*/

void RandomShuffle(ElementType A[], int N)
{
    int temp;
    for(int i = 0; i < N; i++)
    {
        int j = rand()%(N-i) + i;
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }
}

void PrintArray(ElementType A[], int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}