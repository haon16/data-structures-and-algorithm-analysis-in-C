//2020年12月7日 15:42:46
//图的创建

#ifndef _Graph_H
#define _Graph_H

#define MAXVERTEX 20

//邻接表中表对应的链表的顶点
typedef struct ENode
{
    int Vex;            //该边所指向的顶点的位置
    struct ENode *NextEdge;    //指向下一条弧的指针
}ENode;

//邻接表中表的顶点
typedef struct VNode
{
    char Data;          //顶点信息
    ENode *FirstEdge;   //指向第一条依附该顶点的弧
}VNode;

//邻接表
typedef struct GraphRecord
{
    int VexNum;         //图的顶点的数目
    int EdgeNum;        //图的边的数目
    VNode Vexs[MAXVERTEX];
}*Graph;

//读取一个输入字符
char ReadChar();

//根据顶点值获取位置索引
int GetPosition(Graph G, char ch);

//创建邻接表
Graph CreateGraph();

//打印邻接表图
void PrintGraph(Graph G);

#endif      /* _Graph_H */