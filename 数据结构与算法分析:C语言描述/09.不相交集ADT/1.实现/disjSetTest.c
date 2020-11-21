//2020年11月21日 14:29:30
//测试不相交集

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "disjSet.h"

int main()
{
    srand((unsigned)time(NULL));

    DisjSet S;
    Initialize(S);
    PrintDisjSet(S);

    for(int i = 0; i < 5; i++)
    {
        int r1 = rand()%NumSets + 1;
        int r2 = rand()%NumSets + 1;
        SetUnion(S, r1, r2);
    }
    PrintDisjSet(S);

    for(int i = 0; i < 5; i++)
    {
        int r1 = rand()%NumSets + 1;
        printf("%d的根是%d\n", r1, Find(r1, S));
    }
}