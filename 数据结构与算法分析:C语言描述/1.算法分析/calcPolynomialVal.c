//2020年10月31日21点31分
//计算多项式值

#include <stdio.h>
#include <time.h>
#include <math.h>   //数学函数位于libm.so库文件中， 编译时要加 -lm    
                    //大部分库函数位于libc.so库文件，一般不用加-lc，因为这是gcc的默认选项
                    //多线程库libpthread.so    编译加 -pthread

#define MAXN 10
#define MAXK 1e7
typedef double(*FUN)(int n, double a[], double x);

double f1(int n, double a[], double x)
{
    double p = a[0];
    for(int i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));       //一次循环执行i-1+1次乘法，总共执行（1+2+3+...+n） = (n*n+n/)2次乘法
    
    return p;
}

double f2(int n, double a[], double x)
{
    double p = a[n];
    for(int i = n; i > 0; i--)
        p = a[i-1] + x*p;               //一次乘法执行1次乘法，总共n次乘法

    return p; 
}

void testFun(FUN fun, int n, double a[], double x)
{
    clock_t start = clock();
    for(int i = 0; i < MAXK; i++)
        fun(n, a, x);
    clock_t stop = clock();

    double duration = ((double)(stop - start))/CLOCKS_PER_SEC/MAXK;
    printf("ticks = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
}

int main()
{
    double a[MAXN];
    for(int i = 0; i < MAXN; i++)
        a[i] = (double)i;
    
    printf("f1 result:\n");
    testFun(f1, MAXN-1, a, 1.1);
    printf("\nf2 result:\n");
    testFun(f2, MAXN-1, a, 1.1);

    return 0;
}