//2020年12月9日 11:36:49
//最短路径算法实现

#ifndef _ShortestPath_H
#define _ShortestPath_H

#include "../1.实现/graph.h"

struct TableEntry;
typedef struct TableEntry *Table;

//创建并初始化Table
Table CreatTable(int VertexNum);

//打印Table
void PrintTable(Graph G, Table T);

//打印路径
void PrintPath(Graph G, Table T, char cEnd);

//清空Table
void MakeTableEmpty(Table T, int VertexNum);


//无权最短路径
void UnweightShortestPath(Graph G, Table T, char cBegin);


//获取权重
int GetWeight(Graph G, int Begin, int End);

//打印权重及路径
void PrintWeightAndPath(Graph G, Table T, char cBegin);

//dijkstra算法
void Dijkstra(Graph G, Table T, char cBegin);

#endif      /* _ShortestPath_H */