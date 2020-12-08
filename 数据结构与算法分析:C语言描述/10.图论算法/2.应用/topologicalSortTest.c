//2020年12月8日 15:16:04
//测试拓扑排序

#include "topologicalSort.h"

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);
    TopologicalSort(G);

    return 0;
}