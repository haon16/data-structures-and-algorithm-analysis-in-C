//2020年12月17日 20:57:44
//最小生成树（最小权重生成树）实现

#include <stdio.h>
#include "minimumSpanningTree.h"
#include "../../base.h"

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