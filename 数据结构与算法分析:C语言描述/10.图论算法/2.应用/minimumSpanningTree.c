//2020年12月17日 20:57:44
//最小生成树（最小权重生成树）实现

#include <stdio.h>
#include <stdlib.h>
#include "minimumSpanningTree.h"
#include "../../base.h"
#include "../../09.不相交集ADT/1.实现/disjSet.h"


void PrintLinkInfoAndTotalWeight(Graph G, Table T)
{
    int sum = 0;
    for(int i = 0; i < G->VexNum; i++)
    {
        if(T[i].Path != NOTAVERTEX)
        {
            //printf("[%c-%c](%d)\n", G->Vexs[i].Data, G->Vexs[T[i].Path].Data, T[i].Dist);
            PrintPath(G, T, G->Vexs[i].Data);
            sum += T[i].Dist;
        }
    }
    printf("total weight = %d\n", sum);
}

void Prim(Graph G, Table T, char cBegin)
{
    int Pos = GetPosition(G, cBegin);
    if(Pos == NOTIXIST)
        Error("Invalid input");
    
    for(int i = 0; i < G->VexNum; i++)
    {
        T[i].Dist = GetWeight(G, Pos, i);
        if(i != Pos && T[i].Dist != INFINITY)
        {
            T[i].Path = Pos;
        }
    }

    T[Pos].Known = TRUE;
    T[Pos].Dist = 0;

    int k = NOTAVERTEX, min, temp;
    for(int i = 1; i < G->VexNum; i++)
    {
        min = INFINITY;
        for(int j = 0; j < G->VexNum; j++)
        {
            if(T[j].Known == FALSE && T[j].Dist < min)
            {
                min = T[j].Dist;
                k = j;
            }
        }
        
        T[k].Known = TRUE;

        for(int j = 0; j < G->VexNum; j++)
        {
            if(T[j].Known == FALSE)
            {
                temp = GetWeight(G, k, j);
                if(temp < T[j].Dist)
                {
                    T[j].Dist = temp;
                    T[j].Path = k;
                }
            }
        }
    }
}

/*-------------------------------------------------------------------------------------*/
typedef struct EdgeRecord
{
    char cBegin;
    char cEnd;
    int weight;
}*Edge;

//读取图中边的数据
static Edge ReadGraphIntoEdgeInfo(Graph G)
{
    Edge E = (Edge)malloc(sizeof(struct EdgeRecord) * G->EdgeNum);
    if(E == NULL)
        FatalError("Out of space!!!");
    
    int Index = 0;
    for(int i = 0; i < G->VexNum; i++)
    {
        ENode *Node = G->Vexs[i].FirstEdge;
        while(Node != NULL)
        {
            if(Node->Vex > i)           //无向图两个顶点互相指向对方，这里是统计边的情况，使用>或<判断，取一次记录就行
            {
                E[Index].cBegin = G->Vexs[i].Data;
                E[Index].cEnd = G->Vexs[Node->Vex].Data;
                E[Index].weight = Node->Weight;
                Index++;
            }
            Node = Node->NextEdge;
        } 
    }
    return E;
}

//对边的数据进行排序
static void SortEdgeSet(Edge E, int Length)
{
    for(int i = 0; i < Length; i++)
    {
        for(int j = i+1; j < Length; j++)
        {
            if(E[i].weight > E[j].weight)
            {
                struct EdgeRecord Temp = E[i];  //交换边数据
                E[i] = E[j];
                E[j] = Temp;
            }
        }
    }
}

void Kruskal(Graph G)
{
    Edge E = ReadGraphIntoEdgeInfo(G);
    SortEdgeSet(E, G->EdgeNum);

    int Arr[MAXVERTEX] = {0};    
    
    DisjSet S;
    Initialize(S);
    int pos1, pos2;
    int Uset, Vset;
    int Index = 0;
    
    for (int i = 0; i < G->EdgeNum; i++)
    {
        PrintDisjSet(S);
        pos1 = GetPosition(G, E[i].cBegin);
        pos2 = GetPosition(G, E[i].cEnd);
        Uset = Find(pos1, S);
        printf("pos1=%d, Uset=%d\n", pos1, Uset);
        Vset = Find(pos2, S);
        printf("pos2=%d, Vset=%d\n", pos2, Vset);
        if(Uset != Vset)
        {
            SetUnion(S, Uset, Vset);
            PrintDisjSet(S);
            Arr[Index++] = i;
        }
    }

    int sum = 0;
    for(int j = 0; j < Index; j++)
    {
        printf("[%c-%c](%d)\n", E[Arr[j]].cBegin, E[Arr[j]].cEnd, E[Arr[j]].weight);
        sum += E[Arr[j]].weight;
    }
    printf("total weight = %d\n", sum);
}