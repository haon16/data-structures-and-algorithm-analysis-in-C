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

int GetPosition(Graph *pG, char ch)
{
    for(int i = 0; i < pG->VexNum; i++)
    {
        if(pG->Vexs[i].Data == ch)
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

Graph *CreateGraph()
{
    int VexNum, EdgeNum;
    printf("Input vertex number: ");
    scanf("%d", &VexNum);
    printf("input edge number: ");
    scanf("%d", &EdgeNum);
    if(VexNum < 1 || EdgeNum < 1 || EdgeNum > VexNum*(VexNum-1))
        FatalError("Input error!!!");

    Graph *pG = (Graph *)malloc(sizeof(Graph));
    if(pG == NULL)
        FatalError("Out of space!!!");

    memset(pG, 0, sizeof(Graph));
    pG->VexNum = VexNum;
    pG->EdgeNum = EdgeNum;

    //初始化邻接表的顶点
    for(int i = 0; i < pG->VexNum; i++)
    {
        printf("vertex[%d]: ", i);
        pG->Vexs[i].Data = ReadChar();
        pG->Vexs[i].FirstEdge = NULL;
    }

    //初始化邻接表的边
    char ch1, ch2;
    int pos1, pos2;
    ENode *Node;
    for(int i = 0; i < pG->EdgeNum; i++)
    {
        //读取边的起始顶点和结束顶点
        printf("edge[%d]: ", i);
        ch1 = ReadChar();
        ch2 = ReadChar();

        pos1 = GetPosition(pG, ch1);
        pos2 = GetPosition(pG, ch2);

        //创建结点并链接
        Node = (ENode *)malloc(sizeof(ENode));
        Node->Vex = pos2;
        if(pG->Vexs[pos1].FirstEdge == NULL)
            pG->Vexs[pos1].FirstEdge = Node;
        else
            LinkLast(pG->Vexs[pos1].FirstEdge, Node);
    }

    return pG;
}

void PrintGraph(Graph *pG)
{
    ENode *Node;
    printf("List Graph:\n");
    for(int i = 0; i < pG->VexNum; i++)
    {
        printf("[%d%c]", i, pG->Vexs[i].Data);
        Node = pG->Vexs[i].FirstEdge;
        while(Node != NULL)
        {
            printf(" -> [%d%c]", Node->Vex, pG->Vexs[Node->Vex].Data);
            Node = Node->NextEdge;
        }
        printf("\n");
    }
}