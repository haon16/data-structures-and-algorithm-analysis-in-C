//2020年12月8日 14:25:56
//拓扑排序实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "topologicalSort.h"
#include "../../04.队列/1.实现/arrayQueue.h"

void TopologicalSort(Graph G)
{
    int VNum = G->VexNum;
    int *Indegree = (int *)malloc(VNum * sizeof(int));
    char *TopNum = (char *)malloc(VNum * sizeof(char));
    Queue Q = CreateQueue(VNum);
    if(!Indegree || !TopNum || !Q)
        FatalError("Out of space!!!");
    memset(Indegree, 0, sizeof(int) * VNum);
    memset(TopNum, 0, sizeof(char) * VNum);
    
    //统计每个顶点的入度数
    ENode *Node;
    for(int i = 0; i < VNum; i++)
    {
        Node = G->Vexs[i].FirstEdge;
        while(Node != NULL)
        {
            Indegree[Node->Vex]++;
            Node = Node->NextEdge;
        }
    }
    
    //将所有入度为0的顶点入队列
    for(int i = 0; i < VNum; i++)
    {
        if(Indegree[i] == 0)
            Enqueue(i, Q);
    }
    
    int Index = 0;
    while(!IsEmpty(Q))
    {
        int Vertex = FrontAndDequeue(Q);
        TopNum[Index++] = G->Vexs[Vertex].Data;

        //与Node相关联的结点的入度减1，若减为0则入队列
        Node = G->Vexs[Vertex].FirstEdge;
        while(Node != NULL)
        {
            Indegree[Node->Vex]--;
            if(Indegree[Node->Vex] == 0)
                Enqueue(Node->Vex, Q);
            
            Node = Node->NextEdge;
        }
    }

    if(Index != VNum)
        Error("Graph has a cycle");
    
    //打印拓扑排序结果
    printf("Toplogical Sort: ");
    for(int i = 0; i < VNum; i++)
    {
        printf("%c ", TopNum[i]);
    }
    printf("\n");
    
    free(Indegree);
    free(TopNum);
    DisposeQueue(Q);
}