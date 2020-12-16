//2020年12月9日 11:40:58
//无权最短路径实现

#include <stdio.h>
#include <stdlib.h>
#include "shortestPath.h"
#include "../../base.h"
#include "../../04.队列/1.实现/arrayQueue.h"

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

Table CreatTable(int VertexNum)
{
    Table T = (Table)malloc(sizeof(struct TableEntry) * MAXVERTEX);
    if(T == NULL)
        FatalError("Out of space!!!");


    for(int i = 0; i < VertexNum; i++)
    {
        T[i].Known = FALSE;
        T[i].Dist = INFINITY;
        T[i].Path = NOTAVERTEX;
    }
    return T;
}

void PrintTable(Graph G, Table T)
{
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("[%d%c] Known = %d, Dist = %d, Path =  %d\n", i, G->Vexs[i].Data, T[i].Known, T[i].Dist, T[i].Path);
    }
}

static void Print(Graph G, Table T, int Pos)
{
    if(T[Pos].Path != NOTAVERTEX)
    {
        Print(G, T, T[Pos].Path);
        printf(" -> ");
    }
    printf("%c", G->Vexs[Pos].Data);
}

void PrintPath(Graph G, Table T, char cEnd)
{
    int Pos = GetPosition(G, cEnd);

    if(T[Pos].Path == NOTAVERTEX)
    {    
        printf("不存在该路径\n");
        return;
    }

    printf("shortest path: ");
    Print(G, T, Pos);
    printf("\n");
}

void MakeTableEmpty(Table T, int VertexNum)
{
    for(int i = 0; i < VertexNum; i++)
    {
        T[i].Known = FALSE;
        T[i].Dist = INFINITY;
        T[i].Path = NOTAVERTEX;
    }
}

void UnweightShortestPath(Graph G, Table T, char cBegin)
{
    int Pos = GetPosition(G, cBegin);
    if(Pos == NOTIXIST)
        Error("Invalid input");

    T[Pos].Dist = 0;

    Queue Q = CreateQueue(G->VexNum);
    Enqueue(Pos, Q);

    ENode *Node;
    while(!IsEmpty(Q))
    {
        int Index = FrontAndDequeue(Q);
        T[Index].Known = TRUE;

        Node = G->Vexs[Index].FirstEdge;
        while(Node != NULL)
        {
            if(T[Node->Vex].Dist == INFINITY)       //更新该顶点所指向的未知顶点的信息
            {
                T[Node->Vex].Dist = T[Index].Dist + 1;
                T[Node->Vex].Path = Index;
                Enqueue(Node->Vex, Q);
            }
            Node = Node->NextEdge;
        }
    }

    DisposeQueue(Q);
}

int GetWeight(Graph G, int Begin, int End)
{
    if(Begin == End)
        return 0;

    ENode *Node = G->Vexs[Begin].FirstEdge;
    while(Node != NULL)
    {
        if(Node->Vex == End)
            return Node->Weight;
        Node = Node->NextEdge;
    }
    return INFINITY;
}

void PrintWeightAndPath(Graph G, Table T, char cBegin)
{
    int Pos = GetPosition(G, cBegin);
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("shortest(%c, %c)=%d\n", G->Vexs[Pos].Data, G->Vexs[i].Data, T[i].Dist);
        PrintPath(G , T, G->Vexs[i].Data);
        printf("\n");
    }
}

void Dijkstra(Graph G, Table T, char cBegin)
{
    int Pos = GetPosition(G, cBegin);
    if(Pos == NOTIXIST)
        Error("Invalid input");

    for(int i = 0; i < G->VexNum; i++)
    {
        T[i].Dist = GetWeight(G, Pos, i);           //起始点到各顶点的权重
        if(i != Pos && T[i].Dist != INFINITY)       //对起始点所指向的顶点直接更新前驱顶点
        {
            T[i].Path = Pos;
        }
    }

    T[Pos].Known = TRUE;
    T[Pos].Dist = 0;
    
    int k = -1, min, temp;
    for(int i = 1; i < G->VexNum; i++)              //遍历G->VexNum-1次，每次找出一个顶点的最短路径
    {
        min = INFINITY;                         
        for(int j = 0; j < G->VexNum; j++)          //在未获取最短路径的顶点中，找到离起始点最近的顶点
        {
            if(T[j].Known == FALSE && T[j].Dist < min)
            {
                min = T[j].Dist;
                k = j;
            }
        }
        if(k == -1)
        {
            printf("该顶点无通往其他顶点的路径\n");
            return;
        }

        T[k].Known = TRUE;                          //标记该顶点为已知，已获取到最短路径

        for(int j = 0; j < G->VexNum; j++)          //更新当前顶点所指向的未知的顶点的路径信息，更新前驱顶点
        {
            temp = GetWeight(G, k, j);
            temp = (temp == INFINITY ? INFINITY : min + temp);
            if(T[j].Known == FALSE && temp < T[j].Dist)
            {
                T[j].Dist = temp;
                T[j].Path = k;
            }
        }
    }
}