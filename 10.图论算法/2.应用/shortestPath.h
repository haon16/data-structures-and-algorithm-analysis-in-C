//2020年12月9日 11:36:49
//最短路径算法实现

#ifndef _ShortestPath_H
#define _ShortestPath_H

#include "../1.实现/graph.h"

#define TRUE 1
#define FALSE 0
#define INFINITY 65535
#define NOTAVERTEX -1

struct TableEntry
{
    int Known;      //该顶点是否被遍历
    int Dist;       //当前顶点与开始顶点的距离
    int Path;       //与当前结点连接构成边的顶点
};

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

//dijkstra算法（赋权图且无负边值）
void Dijkstra(Graph G, Table T, char cBegin);


//具有负边值的赋权最短路算法
void WeightedNegative(Graph G, Table T, char cBegin);

#endif      /* _ShortestPath_H */