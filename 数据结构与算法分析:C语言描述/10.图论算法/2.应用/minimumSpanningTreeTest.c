//2020年12月17日 22:08:44
//测试最小生成树（最小权重生成树）

#include <stdio.h>
#include "minimumSpanningTree.h"

void TestPrim(Graph G, Table T);

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);

    Table T = CreatTable(G->VexNum);

    printf("Choice : 1 for testing Prim: ");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        TestPrim(G, T);
        break;
    default:
        break;
    }

    return 0;
}

void TestPrim(Graph G, Table T)
{
    char ch;
    do
    {
        char ch1;
        printf("Input begin point: ");
        ch1 = ReadChar();
        Prim(G, T, ch1);
        PrintLinkInfoAndTotalWeight(G, T);

        MakeTableEmpty(T, G->VexNum);
        getchar();
        printf("Continue input?(Y/N) : ");
        ch = getchar();

    }while(ch == 'Y' || ch == 'y');
}