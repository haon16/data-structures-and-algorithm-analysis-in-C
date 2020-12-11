//2020年12月7日 16:17:36
//图的创建

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "../../base.h"

#define IsLetter(ch) ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))

char ReadChar()
{
    char ch;
    
    do
    {
        ch = getchar();
    } while(!IsLetter(ch));
    
    return ch;
}

int GetPosition(Graph G, char ch)
{
    for(int i = 0; i < G->VexNum; i++)
    {
        if(G->Vexs[i].Data == ch)
            return i;
    }
    return -1;
}

void static LinkLast(ENode *List, ENode *Node)
{
    ENode *p = List;
    while(p->NextEdge)
        p = p->NextEdge;
    p->NextEdge = Node;
}

Graph CreateGraph()
{
    int VexNum, EdgeNum;
    printf("Input vertex number: ");
    scanf("%d", &VexNum);
    printf("input edge number: ");
    scanf("%d", &EdgeNum);
    if(VexNum < 1 || VexNum > MAXVERTEX || EdgeNum < 1 || EdgeNum > VexNum*(VexNum-1))
        FatalError("Input error!!!");

    Graph G = (Graph)malloc(sizeof(struct GraphRecord));
    if(G == NULL)
        FatalError("Out of space!!!");

    memset(G, 0, sizeof(Graph));
    G->VexNum = VexNum;
    G->EdgeNum = EdgeNum;

    //初始化邻接表的顶点
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("vertex[%d]: ", i);
        G->Vexs[i].Data = ReadChar();
        G->Vexs[i].FirstEdge = NULL;
    }

    //初始化邻接表的边
    char ch1, ch2;
    int pos1, pos2;
    ENode *Node;
    for(int i = 0; i < G->EdgeNum; i++)
    {
        //读取边的起始顶点和结束顶点
        printf("edge[%d]: ", i);
        ch1 = ReadChar();
        ch2 = ReadChar();

        pos1 = GetPosition(G, ch1);
        pos2 = GetPosition(G, ch2);

        //创建结点并链接
        Node = (ENode *)malloc(sizeof(ENode));
        Node->Vex = pos2;
        if(G->Vexs[pos1].FirstEdge == NULL)
            G->Vexs[pos1].FirstEdge = Node;
        else
            LinkLast(G->Vexs[pos1].FirstEdge, Node);
    }

    return G;
}

void PrintGraph(Graph G)
{
    ENode *Node;
    printf("List Graph:\n");
    for(int i = 0; i < G->VexNum; i++)
    {
        printf("[%d%c]", i, G->Vexs[i].Data);
        Node = G->Vexs[i].FirstEdge;
        while(Node != NULL)
        {
            printf(" -> [%d%c]", Node->Vex, G->Vexs[Node->Vex].Data);
            Node = Node->NextEdge;
        }
        printf("\n");
    }
}