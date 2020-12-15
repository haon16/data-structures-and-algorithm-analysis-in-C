//2020年12月9日 11:40:58
//无权最短路径实现

#include <stdio.h>
#include <stdlib.h>
#include "unweightShortestPath.h"
#include "../../base.h"
#include "../../04.队列/1.实现/arrayQueue.h"

#define TRUE 1
#define FALSE 0
#define INFINITY 65535
#define NOTAVERTEX -1

struct TableEntry
{
    int Known;  //该顶点是否被遍历
    int Dist;   //当前顶点与开始顶点的距离
    int Path;   //与当前结点连接构成边的顶点
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
            if(T[Node->Vex].Dist == INFINITY)
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