//2020年12月9日 16:19:24
//测试无权最短路径

#include <stdio.h>
#include "unweightShortestPath.h"

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);

    Table T = CreatTable(G->VexNum);
    char ch;
    do
    {
        printf("input start point and end point: ");
        char ch1 = ReadChar();
        char ch2 = ReadChar();

        UnweightShortestPath(G, T, ch1);
        PrintTable(G, T);
        PrintPath(G, T, ch2);

        MakeTableEmpty(T, G->VexNum);
        getchar();
        printf("Continue input?(Y/N) : ");
        ch = getchar();

    }while(ch == 'Y' || ch == 'y');

    return 0;
}