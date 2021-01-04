//2021年1月4日 16:28:57
//测试深度优先搜索以及广度优先搜索遍历图

#include "graphTraverse.h"

int main()
{
    Graph G = CreateGraph();
    PrintGraph(G);

    DFS(G);
    BFS(G);
    
    return 0;
}