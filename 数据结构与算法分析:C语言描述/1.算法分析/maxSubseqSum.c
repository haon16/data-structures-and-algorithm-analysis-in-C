//2020年10月31日22点29分
//最大子列和问题

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100
#define MAXK 1000
typedef int(*FUN)(int a[], int n);

//暴力解法
int MaxSubseqSum1(int a[], int n)       //时间复杂度：N立方
{
    int maxSum = 0;
    int thisSum;
    for(int i = 0; i < n; i++)              //子列左端
    {
        for(int j = i; j < n; j++)          //子列右端
        {
            thisSum = 0;
            for(int k = i; k <= j; k++)      //k每次都从i开始计算子列和
                thisSum += a[k];

            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

//暴力解法优化
int MaxSubseqSum2(int a[], int n)       //时间复杂度：N平方
{
    int maxSum = 0;
    int thisSum;
    for(int i = 0; i < n; i++)          
    {
        thisSum = 0;
        for(int j = i; j < n; j++)      
        {
            thisSum += a[j];                //对于相同的i，不同的j，只要在j-1次循环的基础上累加1项
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}


int Max3(int a, int b, int c)
{
    if(a > b && a > c)
        return a;
    else if(b > a && b > c)
        return b;
    else if(c > a && c > b)
        return c;
    else
        return 0;
}

//分而治之方法
int MaxSubSum(int a[], int left, int right)         //时间复杂度：N*logN
{
    if(left == right)
    {
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    int center = (left + right) / 2;
    int maxLeftSum = MaxSubSum(a, left, center);        //左半边最大子列和
    int maxRightSum = MaxSubSum(a, center+1, right);    //右半边最大子列和

    int maxLeftBorderSum = 0;                           //求跨越分界处的最大子列和
    int leftBorderSum = 0;
    for(int i = center; i >= left; i--)             //分界处往左
    {
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0;
    int rightBorderSum = 0;
    for(int i = center + 1; i <= right; i++)        //分界处往右
    {
        rightBorderSum += a[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return Max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

int MaxSubseqSum3(int a[], int n)
{
    return MaxSubSum(a, 0, n-1); 
}

//在线处理方法
int MaxSubseqSum4(int a[], int n)           //时间复杂度：N
{
    int thisSum = 0;
    int maxSum = 0;
    for(int i = 0; i < n; i++)
    {
        thisSum += a[i];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)        //如果当前子列和为负，则不可能使后面的部分和增大，抛弃之
            thisSum = 0;
    }
    return maxSum;
}

void testFun(FUN fun, int a[], int n)
{
    int res = 0;
    clock_t start = clock();
    for(int i = 0; i < MAXK; i++)
        res = fun(a, n);
    clock_t stop = clock();

    double duration = ((double)(stop - start))/CLOCKS_PER_SEC/MAXK;
    printf("ticks = %f\n", (double)(stop - start));
    printf("duration = %f\n", duration);
    printf("最大子列和为：%d\n", res);
}

int main()
{
    srand((unsigned)time(NULL));
    int a[MAXN] = {0};
    for(int i = 0; i < MAXN; i++)
        a[i] = rand() % 20 - 10;

    printf("暴力解法 result:\n");
    testFun(MaxSubseqSum1, a, MAXN);

    printf("\n暴力解法优化 result:\n");
    testFun(MaxSubseqSum2, a, MAXN);

    printf("\n分而治之方法 result:\n");
    testFun(MaxSubseqSum3, a, MAXN);

    printf("\n在线处理方法 result:\n");
    testFun(MaxSubseqSum4, a, MAXN);

    return 0;
}
