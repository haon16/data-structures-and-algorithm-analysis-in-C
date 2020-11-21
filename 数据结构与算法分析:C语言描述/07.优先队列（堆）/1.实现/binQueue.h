//2020年11月17日 15:44:59
//二项队列的实现

#ifndef _BinQueue_H

#include "../../base.h"

struct BinNode;
struct Collection;

typedef struct BinNode *Position;
typedef struct BinNode *BinTree;
typedef struct Collection *BinQueue;

//判断是否为空
int IsEmpty(BinQueue H);

//初始化
BinQueue Initialize();

//销毁
void Destroy(BinQueue H);

//置空
BinQueue MakeEmpty(BinQueue H);

//合并同样大小的两棵二项树
BinTree CombineTrees(BinTree T1, BinTree T2);

//合并两个优先队列
BinQueue Merge(BinQueue H1, BinQueue H2);

//插入
BinQueue Insert(ElementType Item, BinQueue H);

//删除最小元素
ElementType DeleteMin(BinQueue H);

//遍历输出
void PrintBinHeap(BinQueue H);

#endif      /* _BinQueue_H */