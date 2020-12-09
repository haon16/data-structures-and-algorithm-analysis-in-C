//2020年12月9日 16:19:24
//测试无权最短路径

#include <stdio.h>
#include "unweightShortestPath.h"

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);

    printf("input start point and end point: ");
    char ch1 = ReadChar();
    char ch2 = ReadChar();

    Table T = CreatTable(G->VexNum);
    UnweightShortestPath(G, T, ch1);
    
    PrintTable(G, T);
    PrintPath(G, T, ch2);
    return 0;
}