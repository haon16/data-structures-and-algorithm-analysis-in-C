//2021年1月4日 16:11:56
//使用深度优先搜索以及广度优先搜索遍历图

#include <stdio.h>
#include "graphTraverse.h"

static void DFS1(Graph G, int i, int *Visited)
{
    Visited[i] = 1;
    printf("%c", G->Vexs[i].Data);
    ENode *Node = G->Vexs[i].FirstEdge;
    while(Node != NULL)
    {
        if (!Visited[Node->Vex])
        {
            DFS1(G, Node->Vex, Visited);
        }
        Node = Node->NextEdge;
    }
}

void DFS(Graph G)
{
    int Visited[MAXVERTEX] = {0};       //顶点访问标记

    printf("DFS result: ");
    for(int i = 0; i < G->VexNum; i++)  //保证非连通图也能完全遍历
    {
        if(!Visited[i])
        {
            DFS1(G, i, Visited);
        }
    }
    printf("\n");
}


void BFS(Graph G)
{
    int Queue[MAXVERTEX] = {0};     //辅助数组
    int Front = 0;
    int Rear = 0;
    int Visited[MAXVERTEX] = {0};

    printf("BFS result: ");
    for(int i = 0; i < G->VexNum; i++)
    {
        if(!Visited[i])
        {
            Visited[i] = 1;
            printf("%c", G->Vexs[i].Data);
            Queue[Rear++] = i;      //入队
        }

        while(Front != Rear)
        {
            int Index = Queue[Front++];     //出队
            ENode *Node = G->Vexs[Index].FirstEdge;
            while(Node != NULL)
            {
                if(!Visited[Node->Vex])
                {
                    Visited[Node->Vex] = 1;
                    printf("%c", G->Vexs[Node->Vex].Data);
                    Queue[Rear++] = Node->Vex;
                }
                Node = Node->NextEdge;
            }
        }
    }
    printf("\n");
}