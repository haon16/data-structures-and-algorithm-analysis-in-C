//2020年12月17日 17:38:44
//最小生成树（最小权重生成树）实现

#ifndef _MinimumSpanningTree_h
#define _MinimumSpanningTree_h

#include "../1.实现/graph.h"
#include "shortestPath.h"    //直接用Table，就不重新整合一个头文件了

//输出链路及总权重
void PrintLinkInfoAndTotalWeight(Graph G, Table T);

//Prim算法
void Prim(Graph G, Table T, char cBegin);

//Kruskal算法
void Kruskal(Graph G);



#endif      /* _MinimumSpanningTree_h */