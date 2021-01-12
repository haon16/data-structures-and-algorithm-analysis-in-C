//2020年11月21日 10:51:01
//不相交集合实现

#include <stdio.h>
#include "disjSet.h"

void Initialize(DisjSet S)
{
    for(int i = NumSets; i > 0; i--)
    {
        //进行一次任意的并/按高度求并
        //S[i] = 0;

        //按大小求并（每个根的数据元素记住包含它的数的大小的负值）
        S[i] = -1;
    }
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    //进行一次任意的并
    //S[Root2] = Root1;

    //按大小求并
    if(S[Root1] < S[Root2])
    {
        S[Root2] = Root1;
        S[Root1]--;
    }
    else
    {
        S[Root1] = Root2;
        S[Root2]--;
    }

    //按高度求并（只有两棵相同深度的树求并时树的高度才增加，此时树的高度增1）
    /*
    if(S[Root2] < S[Root1])     //Root2 is deeper set
        S[Root1] = Root2;       //Make Root2 new root
    else
    {
        if(S[Root1] == S[Root2])    //Same height
            S[Root1]--;             //so update
        S[Root2] = Root1;
    }
    */
}

SetType Find(ElementType X, DisjSet S)
{
    if(S[X] <= 0)
        return X;
    else
    {
        //return Find(S[X], S);

        //用路径压缩进行不相交集Find
        //S[X]等于由Find返回的值，这样在集合的根被递归地找到以后，X就直接指向它
        //路径压缩不完全与按高度求并兼容，因为路径压缩可以改变树的高度
        return S[X] = Find(S[X], S);
    }
}

void PrintDisjSet(DisjSet S)
{
    for(int i = 1; i <= NumSets; i++)
        printf("%d\t", S[i]);
    printf("\n");

    for(int i = 1; i <= NumSets; i++)
        printf("%d\t", i);
    printf("\n\n");
}