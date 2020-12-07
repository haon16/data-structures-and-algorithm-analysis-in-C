//2020年11月1日14点27分
//AVL树的实现（带有平衡条件的二叉查找树）

#ifndef _AVLTree_H
#define _AVLTree_H

#include "../../base.h"

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

//创建一棵空树
AvlTree MakeEmpty(AvlTree T);

//查找指定元素
Position Find(ElementType X, AvlTree T);

//查找最小值
Position FindMin(AvlTree T);

//查找最大值
Position FindMax(AvlTree T);

//插入元素
AvlTree Insert(ElementType X, AvlTree T);

//删除元素
AvlTree Delete(ElementType X, AvlTree T);

//获取该结点的元素
ElementType Retrieve(Position P);

//中序遍历(按顺序从小到大输出)
void InorderTraversal(AvlTree T);

#endif       /* _AVLTree_H */