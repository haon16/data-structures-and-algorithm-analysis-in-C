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
#define NOTEXIST -1

typedef struct InfoRecord
{
    int Known;  //该顶点是否被遍历
    int Dist;   //当前顶点与开始顶点的距离
    int Path;   //与当前结点连接构成边的顶点
}*Info;

struct TableRecord
{
    Info Array[MAX];
};

Table CreatTable(int VertexNum)
{
    Table T = (Table)malloc(sizeof(struct TableRecord));
    if(T == NULL)
        FatalError("Out of space!!!");

    for(int i = 0; i < VertexNum; i++)
    {
        T->Array[i] = (Info)malloc(sizeof(struct InfoRecord));
        if(T->Array[i] == NULL)
            FatalError("Out of space!!!");

        T->Array[i]->Known = FALSE;
        T->Array[i]->Dist = INFINITY;
        T->Array[i]->Path = NOTEXIST;
    }
    return T;
}

void UnweightShortestPath(Graph G, Table T, char cBegin)
{
    int Pos = GetPosition(G, cBegin);
    T->Array[Pos]->Dist = 0;

    Queue Q = CreateQueue(G->VexNum);
    Enqueue(Pos, Q);

    ENode *Node;
    while(!IsEmpty(Q))
    {
        int Index = FrontAndDequeue(Q);
        T->Array[Index]->Known = TRUE;

        Node = G->Vexs[Index].FirstEdge;
        while(Node != NULL)
        {
            if(T->Array[Node->Vex]->Dist == INFINITY)
            {
                T->Array[Node->Vex]->Dist = T->Array[Index]->Dist + 1;
                T->Array[Node->Vex]->Path = Index;
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
        printf("[%d%c] Known = %d, Dist = %d, Path =  %d\n", i, G->Vexs[i].Data, T->Array[i]->Known, T->Array[i]->Dist, T->Array[i]->Path);
    }
}

static void Print(Graph G, Table T, int Pos)
{
    if(T->Array[Pos]->Path != NOTEXIST)
    {
        Print(G, T, T->Array[Pos]->Path);
        printf(" -> ");
    }
    printf("%c", G->Vexs[Pos].Data);
}

void PrintPath(Graph G, Table T, char cEnd)
{
    int Pos = GetPosition(G, cEnd);

    if(T->Array[Pos]->Path == NOTEXIST)
    {    
        printf("不存在该路径\n");
        return;
    }

    printf("shortest path: ");
    Print(G, T, Pos);
    printf("\n");
}
