//2020年12月9日 11:36:49
//无权最短路径实现

#ifndef _UnweightShortestPath_H
#define _UnweightShortestPath_H

#include "../1.实现/graph.h"

struct TableEntry;
typedef struct TableEntry (*Table)[MAXVERTEX];

//创建并初始化Table
Table CreatTable(int VertexNum);

//无权最短路径
void UnweightShortestPath(Graph G, Table T, char cBegin);

//打印Table
void PrintTable(Graph G, Table T);

//打印路径
void PrintPath(Graph G, Table T, char cEnd);

#endif      /* _UnweightShortestPath_H */